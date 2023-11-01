#!/bin/bash

ysyxid=000000
cpu_tests_dir=./bin/non-output/cpu-tests/
riscv_tests_dir=./bin/non-output/riscv-tests/
regression_tests_dir=./bin/custom-output/

mkdir build

function tests {
  bin_files=`eval "find $1 -mindepth 1 -maxdepth 1 -regex \".*\.\(bin\)\""`
  for bin_file in $bin_files; do
    file_name=`basename ${bin_file%.*}`
    printf "[%30s] " $file_name
    log_file=./build/$file_name.log
    ./build.sh -e cpu_diff -d -b -s -a -i  $bin_file &> $log_file
    if (grep 'HIT GOOD TRAP' $log_file > /dev/null) then
      echo -e "\033[1;32mPASS!\033[0m"
      rm $log_file
    else
      echo -e "\033[1;31mFAIL!\033[0m see $log_file for more information"
    fi
  done
  wait
}

while getopts 'crat:w:ls' OPT; do
  case $OPT in
    c)
      tests $cpu_tests_dir;;
    r)
      tests $riscv_tests_dir;;
    a)
      tests $regression_tests_dir;;
    t)
      example="$OPTARG"
      ./build/emu -i ${cpu_tests_dir}${example}-cpu-tests.bin;;
    w)
      example="$OPTARG"
      ./build/emu -i ${cpu_tests_dir}${example}-cpu-tests.bin -b 0 --dump-wave --wave-path=./build/wave.vcd;;
    ?)
      echo "Error: unknown arguments"
  esac
done
