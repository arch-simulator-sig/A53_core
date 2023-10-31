
`timescale 1ns / 1ps

`define ZERO_WORD  64'h00000000_00000000
`define PC_START   64'h00000000_80000000  
`define REG_BUS    63 : 0     
`define INST_ADD   8'h11

`define RISCV_PRIV_MODE_U   0
`define RISCV_PRIV_MODE_S   1
`define RISCV_PRIV_MODE_M   3

`define ID2EX_WD 600
`define EX2MEM_WD 600
`define MEM2WB_WD 600
`define WB2RF_WD 600
`define MEM2EX_WD 600
`define WB2EX_WD 600

`define StallBus 6