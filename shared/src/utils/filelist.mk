ifneq ($(CONFIG_ITRACE)$(CONFIG_IQUEUE),)
CXXSRC += shared/src/utils/disasm.cc
CXXFLAGS += $(shell llvm-config --cxxflags) -fPIE
LIBS += $(shell llvm-config --libs)
LDFLAGS += $(shell llvm-config --ldflags)
endif
