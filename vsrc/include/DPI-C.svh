`ifndef __DPI_C_SV__
`define __DPI_C_SV__

`ifdef CONFIG_VERILATOR

import "DPI-C" function void pmem_read(
    input  longint raddr,
    output longint rdata
);

import "DPI-C" function void pmem_write(
    input longint waddr,
    input longint wdata,
    input byte wmask
);

import "DPI-C" function void itrace(
    longint i,
);

import "DPI-C" function void mtrace(
    input longint addr,
    input int width,
    input bit wr_or_rd,
    input longint data,
    input longint pc
);

import "DPI-C" function void call_step(input longint pc);

`endif
`endif
