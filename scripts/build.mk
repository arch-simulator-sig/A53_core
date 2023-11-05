.DEFAULT_GOAL := all

V_SRC_DIRS += $(V_SRC_HOME)
CC_SRC_DIRS += $(CC_SRC_HOME)

C_SHARED_DIR = $(NEMU_HOME)/shared
C_SHARED_SRC_DIR = $(C_SHARED_DIR)/src

V_INC_PATH += $(abspath $(V_SRC_HOME)/include)
C_INC_PATH += $(abspath $(CC_SRC_HOME)/include) $(abspath $(C_SHARED_DIR)/include)

V_SRC_EXCLUDE += $(V_INC_PATH)

BUILD_DIR = $(WORK_DIR)/build
OBJ_DIR = $(BUILD_DIR)/obj_dir

TOPNAME = Top
BIN = $(BUILD_DIR)/npc
PRESV = $(BUILD_DIR)/out.sv

# source
CORE_VSRCS += $(shell find $(abspath $(V_SRC_HOME)/core) -name "*.sv" -or -name "*.v")
UTIL_VSRCS += $(shell find $(abspath $(V_SRC_HOME)/utils) -name "*.sv" -or -name "*.v")
VSRCS += $(shell find $(abspath $(V_SRC_DIRS)) -path "$(V_SRC_EXCLUDE)" -prune -type f -or -name "*.v" -or -name "*.sv")
CSRCS += $(shell find $(abspath $(CC_SRC_DIRS)) -name "*.cc" -or -name "*.cpp")
C_SHARED_SRCS += $(shell find $(abspath $(C_SHARED_SRC_DIR)) -name "*.c")
CC_SHARED_SRCS += $(shell find $(abspath $(C_SHARED_SRC_DIR)) -name "*.cc")
OBJS += $(patsubst $(abspath $(C_SHARED_SRC_DIR))/%.c, $(OBJ_DIR)/%.o, $(C_SHARED_SRCS)) $(patsubst $(abspath $(C_SHARED_SRC_DIR))/%.cc, $(OBJ_DIR)/%.o, $(CC_SHARED_SRCS))

# These obj files are not used directly, but by the makefile which Verilator produced. We use it to fix dependencies correctly.
DEPS = $(addprefix $(OBJ_DIR)/, $(notdir $(CSRCS:.cc=.d)))
DEP_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(CSRCS:.cc=.o)))
DEP_FLAG = -CFLAGS -MT'$(OBJ_DIR)/$$@'
$(DEP_OBJS):
	rm -f $@
$(DEPS): $(shell sed -n -i 's/ [a-zA-Z.]*//g' $(DEPS) > /dev/null 2&>1)# remove all relative paths

-include $(DEPS)
-include $(OBJS:.o=.d)

# disasm
SHARED_CXXFLAGS += $(shell llvm-config --cxxflags) -fPIE
LDFLAGS += $(shell llvm-config --ldflags --libs)

# rules for verilator
VERILATOR_CFLAGS += -MMD --build --exe -cc -O3 --x-assign fast --x-initial fast --noassert --build-jobs 20
VERILATOR_CFLAGS += --trace --trace-structs
V_INCFLAGS = $(addprefix -I, $(V_INC_PATH))
C_INCFLAGS = $(addprefix -I, $(C_INC_PATH))
CFLAGS += $(C_INCFLAGS) -O2 -MMD -Wall -Werror -g
CFLAGS +=  -Wno-macro-redefined -Wno-unused-result -Wno-unused-variable -Wno-bitwise-instead-of-logical
CXXFLAGS := $(CFLAGS) -std=c++17
LDFLAGS += -lSDL2 -lSDL2_image -lreadline -lfmt -no-pie

VPATH = $(CC_SRC_HOME):$(C_SHARED_SRC_DIR)

$(OBJ_DIR)/%.o: %.c
	@echo + CC $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $< -c -o $@

$(OBJ_DIR)/%.o: %.cc
	@echo + CXX $<
	@mkdir -p $(dir $@)
	@$(CXX) $(SHARED_CXXFLAGS) $< -c -o $@

# Decoder Generator
DECODE_GEN = $(WORK_DIR)/tools/DecoderGenerator/decode_gen.py
DECODE_SHEET = $(WORK_DIR)/tools/DecoderGenerator/decode.xlsx
DECODE_CODE = $(V_SRC_HOME)/include/decode_generated.sv
DEOCDE_HEADER = $(DECODE_CODE)h
$(DECODE_CODE): $(DECODE_GEN) $(DECODE_SHEET)
	@python3 $(DECODE_GEN) $(DECODE_SHEET) $(DECODE_CODE) $(DEOCDE_HEADER)

WALLACE_GEN = $(WORK_DIR)/tools/WallaceGenerator/wallace_gen.py
WALLACE_CODE = $(V_SRC_HOME)/include/wallace_generated.sv
$(WALLACE_CODE): $(WALLACE_GEN)
	@python3 $(WALLACE_GEN) $(WALLACE_CODE)

gencode: $(DECODE_CODE) $(WALLACE_CODE)

# build
$(BIN): $(DEP_OBJS) $(VSRCS) $(CSRCS) $(OBJS) $(SV_CONFIG) $(DECODE_CODE)
	$(VERILATOR) $(VERILATOR_CFLAGS) $(V_INCFLAGS) --top-module $(TOPNAME) $(VSRCS) $(CSRCS) $(abspath $(OBJS)) $(addprefix -CFLAGS , $(CXXFLAGS)) $(DEP_FLAG) $(addprefix -LDFLAGS , $(LDFLAGS)) --Mdir $(OBJ_DIR) -o $(abspath $(BIN))
	
pre: $(CORE_VSRCS)
	$(VERILATOR) -E -P $(V_INCFLAGS) -DSYNTHESIS $(CORE_VSRCS) $(UTIL_VSRCS) | sed '/^[[:space:]]*$$/d' > $(PRESV)

all: $(BIN)
.PHONY: all pre decode
