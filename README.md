## ysyx difftest

设置`NEMU_HOME`

```
make menuconfig

make run IMG=
```

或者直接用下面的.config
```
CONFIG_VERILATOR=y
CONFIG_MEM_BASE=0x80000000
CONFIG_MEM_SIZE=0x8000000
CONFIG_DEVICE=y
CONFIG_SERIAL=y
CONFIG_SERIAL_MMIO=0x1000000
CONFIG_TRACE=y
CONFIG_TRACE_START=0
CONFIG_TRACE_END=10000
CONFIG_ITRACE=y
CONFIG_ITRACE_COND="true"
CONFIG_MTRACE=y
CONFIG_MTRACE_LEFT=0x80000000
CONFIG_MTRACE_RIGHT=0x87ffffff
CONFIG_FTRACE=y
CONFIG_DTRACE=y
CONFIG_DIFFTEST=y
CONFIG_MUL_VERIFY=y
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