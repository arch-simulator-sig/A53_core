include /home/unlsycn/Workspaces/ysyx-workbench/npc/Makefile

TOPNAME := MulTest
BIN := ./mul-test
SRCS := $(UTIL_VSRCS) MulTest.sv mul-test.cc

WALLACE_CODE := ./wallace_generated.sv
$(WALLACE_CODE):
	@python3 $(WALLACE_GEN) $(WALLACE_CODE)

$(BIN): $(SRCS) $(WALLACE_CODE)
	$(VERILATOR) $(VERILATOR_CFLAGS) -I. $(V_INCFLAGS) --top-module $(TOPNAME) $(SRCS) $(addprefix -CFLAGS , $(CXXFLAGS)) $(DEP_FLAG) $(addprefix -LDFLAGS , $(LDFLAGS)) -o $(abspath $(BIN))

test: $(BIN)
	@$(BIN)
