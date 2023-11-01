#!/bin/bash

VERSION="0.0.1"

A53_PATH=$(dirname $(readlink -f "$0"))
LIBRARIES_FOLDER=$(A53_PATH)
DIFFTEST_PATH=$(LIBRARIES_FOLDER)/difftest
NEMU_PATH=$(LIBRARIES_FOLDER)/NEMU
DRAMSIM3_FOLDER=$(LIBRARIES_FOLDER)/DRAMsim3
PROJECT_PATH=$(A53_PATH)/projects/cpu_diff/vsrc
DIFFTEST_PARAM=

compile_dramsim3() {
    if [[ ! -f $A53_PATH/$DRAMSIM3_FOLDER/build/libdramsim3.a ]]; then
        [[ ! `dpkg -l | grep cmake` ]] && sudo apt-get --yes install cmake
        mkdir $A53_PATH/$DRAMSIM3_FOLDER/build
        cd $A53_PATH/$DRAMSIM3_FOLDER/build
        cmake -D COSIM=1 ..
        make
        if [ $? -ne 0 ]; then
            echo "Failed to compile dramsim3!!!"
            exit 1
        fi
        cd $A53_PATH
    fi
}

compile_nemu() {
    if [[ ! -f $NEMU_HOME/build/riscv64-nemu-interpreter-so ]]; then
        cd $NEMU_HOME
        make riscv64-ysyx-ref_defconfig
        make
        if [ $? -ne 0 ]; then
            echo "Failed to compile nemu!!!"
            exit 1
        fi
        cd $A53_PATH
    fi
}



compile_difftest() {
    cd $DIFFTEST_PASH
    make DESIGN_DIR=$PROJECT_PATH $DIFFTEST_PARAM
    if [ $? -ne 0 ]; then
        echo "Failed to compile difftest!!!"
        exit 1
    fi
    cd $A53_PATH
}


export NEMU_HOME=$NEMU_HOME
export NOOP_HOME=$PROJECT_PATH
export DRAMSIM3_HOME=$DRAMSIM3_HOME