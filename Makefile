PWD=$(shell pwd)

init:
	git submodule update --init --recursive

verilog:
	make -C difftest difftest_verilog

emu: verilog
	make -C difftest emu

# test: emu
# 	cd	$(PWD)/scripts && bash test.sh -

clean:
	rm -rf build

