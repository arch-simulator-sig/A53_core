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

## 运行test
scripts看test.sh

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


