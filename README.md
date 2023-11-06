## ysyx difftest

设置`NEMU_HOME`

```
make menuconfig 

LOAD coremark.config SAVE AS .config

make run IMG=
```

```
make gencode 可以生成IDU
```

接入 difftest: 在写回寄存器阶段调用`call_step`，参考

```
import "DPI-C" function void set_gpr_ptr(input xlen_t r[]);
            initial
                set_gpr_ptr(regFile);

import "DPI-C" function void set_pc_ptr(input xlen_t pc[]);
            xlen_t pc /*verilator forceable*/;
            assign pc = iDbgInfo.pc;
            initial
                set_pc_ptr(pc);

            xlen_t rPC;

            always @(posedge clk)
            begin
                rPC <= iDbgInfo.pc;
            end
            always @(iDbgInfo)
            begin
                if(iDbgInfo.pc >= `PC_RST_VAL && rPC != iDbgInfo.pc)
                begin
                    call_step(iDbgInfo.pc);
`ifdef CONFIG_ITRACE
                    itrace(`zext(iDbgInfo.inst));
`endif

                end
            end
```