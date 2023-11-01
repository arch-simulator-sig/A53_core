
# 1. detect verilator

VERILATOR_HOME1=/usr/share/verilator
VERILATOR_HOME2=/usr/local/share/verilator
ifeq ($(VERILATOR_HOME1), $(wildcard $(VERILATOR_HOME1)))
VERILATOR_HOME=$(VERILATOR_HOME1)
else ifeq ($(VERILATOR_HOME2), $(wildcard $(VERILATOR_HOME2)))
VERILATOR_HOME=$(VERILATOR_HOME2)
else
#add your verilator include path to this var, then delete this line.
VERILATOR_HOME=/home/yangzhaoxin/opt/verilator/share/verilator
#$(error Please install verilator or config the installed path here.)
endif


VERILATOR_VLTSTD=$(VERILATOR_HOME)

ifeq ($(shell which verilator),)
$(error Did not find Verilator in PATH. Make sure all requirements are installed)
endif

INCLUDE = -I${VERILATOR_HOME}/include 
INCLUDE+= -I$(VERILATOR_HOME)/include/vltstd
VERILATED_SRC = ${VERILATOR_HOME}/include/verilated.cpp ${VERILATOR_HOME}/include/verilated_threads.cpp 
VCD_SRC = ${VERILATOR_HOME}/include/verilated_vcd_c.cpp 
FST_SRC = ${VERILATOR_HOME}/include/verilated_fst_c.cpp
SAVE_SRC = ${VERILATOR_HOME}/include/verilated_save.cpp

#2. PATH

A53_PATH=$(dirname $(readlink -f "$0"))
LIBRARIES_DIR=$(A53_PATH)
DIFFTEST_PATH=$(LIBRARIES_DIR)/difftest
NEMU_PATH=$(LIBRARIES_DIR)/NEMU
DRAMSIM3_DIR=$(LIBRARIES_DIR)/DRAMsim3
SCRIPT_DIR=$(A53_PATH)/scripts
CPU_SRC=$(A53_PATH)/projects/cpu_diff/vsrc

SIMU_TOP_NAME=SimTop
DIFFTEST=difftest


VERILATOR_INCLUDE = -y ${CPU_SRC} 
VERILATOR_SRC += ${CPU_SRC}/*.v



# 3. Config
DUMP_VCD=y
THREAD=16

ifeq ('${DUMP_VCD}', 'y') 
CFLAGS += -DDUMP_VCD 
WAVEFILE = vcd 
WAVEOPTION = 
else
CFLAGS += -DDUMP_FST 
WAVEFILE = fst 
WAVEOPTION = --trace-fst
endif


init:
	cd  bash env.sh

verilog:
	@echo "============================================================================================================="
	@echo "============================================================================================================="
	@echo "COMPILING verilog..."
	@echo "============================================================================================================="
	@echo "============================================================================================================="
	mkdir -p log
	mkdir -p ${OBJ_DIR}
	verilator ${VERILATOR_INCLUDE} ${WAVEOPTION} --savable --threads ${THREAD} -O3 -Wno-fatal -DSIMU -DSIMULATION=1 -Wall --trace -cc ${VFLAGS} ${SIMU_TOP_NAME}.v ${DIFFTEST}.v ${VERILATOR_SRC} 2>&1 | tee log/compile.log
	$(MAKE) -C ${OBJ_DIR} -f "V${SIMU_TOP_NAME}.mk" || exit "$$?"

emu: verilog
	cd $(SCRIPT_DIR) && $(DIFFTEST_PATH) && $(MAKE)  EMU_TRACE=1  emu -j8  

test:
	cd $(SCRIPT_DIR) && bash test.sh -a

coremark:
	cd $(SCRIPT_DIR) && bash test.sh -x

submit:
	cd $(SCRIPT_DIR) && bash submit.sh


clean:

.PHONY: init test coremark clean submit