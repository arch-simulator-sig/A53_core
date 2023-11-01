rm -rf build
rm -rf projects/cpu_diff/build

# riscv-tests
# bash test.sh -r
# rm -rf build

# cpu-tests
# bash test.sh -c
# rm -rf build

# coremark
bash test.sh -x

# bin/custom-output 下面的所有测试
bash test.sh -a