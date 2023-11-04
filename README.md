# 20231101 A53适配修改

initialization:
```
make init
```

提前检查difftest/.mill-version里面版本和现有的mill --version是否匹配

compile:
```
make emu
```

bin dir structure
```
├── coremark
│   └── coremark-riscv64-kjw.bin
├── cpu-tests
│   ├── add-cpu-tests.bin
│   ├── add-cpu-tests.elf
│   ├── add-cpu-tests.txt
    ...
    ...
└── riscv-tests
    ├── addi-riscv-tests.bin
    ├── addi-riscv-tests.elf
    ├── addi-riscv-tests.txt
```

## 运行test
make test
## TODO：
[x] 接入difftest

[ ] 自动测试脚本

[ ] 运行coremark

    1. csr
    2. exception
    3. diff多余信号加宏
    
[ ] 重构

    0. 挑选sram，尝试双核
    1. 乘除法重构
    2. stall重构
    3. 性能模块 btb ras 


sk-nHpU9NaOKJPjSMCUzSkPIskMlxARYF8kcdQtFaKGChgJUeSv