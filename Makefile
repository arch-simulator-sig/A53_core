PWD=$(shell pwd)

init:
	git submodule update --init --recursive
	$(MAKE) -C difftest difftest_verilog

emu:
	$(MAKE) -C difftest emu

test:
	$(MAKE) -C bin-to-run run

clean:
	rm -rf build build-test

