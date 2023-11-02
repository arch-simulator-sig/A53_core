`include "defines.v"
module mycpu_pipeline
#(
    parameter ID2EX_WD = 50,
    parameter EX2MEM_WD = 50,
    parameter MEM2WB_WD = 50,
    parameter WB2RF_WD = 50,

    parameter MEM2EX_WD = 50,
    parameter WB2EX_WD = 50
)(
    input  wire clk,
    input  wire rst_n,
    input  wire timer_int,
    input  wire stallreq_axi,

    output wire         inst_sram_en,
    output wire [7:0]   inst_sram_we,
    output wire [63:0]  inst_sram_addr,
    output wire [63:0]  inst_sram_wdata,
    input  wire [63:0]  inst_sram_rdata,

    output wire         data_sram_en,
    output wire [7:0]   data_sram_we,
    output wire [63:0]  data_sram_addr,
    output wire [63:0]  data_sram_wdata,
    input  wire [63:0]  data_sram_rdata,

    output wire [63:0]  debug_wb_pc,
    output wire [31:0]  debug_wb_inst,
    output wire [7:0]   debug_wb_rf_we,
    output wire [4:0]   debug_wb_rf_wnum,
    output wire [63:0]  debug_wb_rf_wdata,
    output wire [63:0]  satp,
    output wire [63:0]  mstatus,
    output wire [63:0]  mie,
    output wire [63:0]  mtvec,
    output wire [63:0]  mtimecmp,
    output wire [63:0]  mtime,
    output wire [63:0]  mscratch,
    output wire [63:0]  mepc,
    output wire [63:0]  mcause,
    output wire [63:0]  mip,
    output wire [63:0]  regs_o[0:31]
);

    wire [ID2EX_WD-1:0] id2ex_bus;
    wire [EX2MEM_WD-1:0] ex2mem_bus;
    wire [MEM2WB_WD-1:0] mem2wb_bus;
    wire [WB2RF_WD-1:0] wb2rf_bus;
    wire [MEM2EX_WD-1:0] mem2ex_fwd;
    wire [WB2EX_WD-1:0] wb2ex_fwd;
    wire [64:0] br_bus;
    wire [31:0] csr_vec_h;
    wire stallreq_ex;
    wire stallreq_id;
    wire flush;
    wire [5:0] stall;
    wire except_en;
    wire [63:0] new_pc;

    IF u_IF(
    	.clk             (clk             ),
        .rst_n           (rst_n           ),
        .timer_int       (timer_int       ),
        
        .flush           (flush           ),
        .stall           (stall           ),
        .new_pc          (new_pc          ),
        .br_bus          (br_bus          ),
        .csr_vec_h       (csr_vec_h       ),
        .inst_sram_en    (inst_sram_en    ),
        .inst_sram_we    (inst_sram_we    ),
        .inst_sram_addr  (inst_sram_addr  ),
        .inst_sram_wdata (inst_sram_wdata )
    );

    ID 
    #(
        .ID2EX_WD (ID2EX_WD ),
        .WB2RF_WD (WB2RF_WD )
    )
    u_ID(
    	.clk             (clk             ),
        .rst_n           (rst_n           ),
        .flush           (flush           ),
        .stall           (stall           ),
        .br_e            (br_bus[64]      ),
        .stallreq_id     (stallreq_id     ),
        .pc_valid        (inst_sram_en    ),
        .pc              (inst_sram_addr  ),
        .inst_sram_rdata (inst_sram_rdata ),
        .csr_vec_h       (csr_vec_h       ),
        .wb2rf_bus       (wb2rf_bus       ),
        .id2ex_bus       (id2ex_bus       ),
        .regs_o          (regs_o)
    );

    EX 
    #(
        .ID2EX_WD  (ID2EX_WD  ),
        .EX2MEM_WD (EX2MEM_WD ),
        .MEM2EX_WD (MEM2EX_WD ),
        .WB2EX_WD  (WB2EX_WD  )
    )
    u_EX(
    	.clk             (clk             ),
        .rst_n           (rst_n           ),
        .flush           (flush           ),
        .stall           (stall           ),
        .stallreq_ex     (stallreq_ex     ),
        .id2ex_bus       (id2ex_bus       ),
        .mem2ex_fwd      (mem2ex_fwd      ),
        .wb2ex_fwd       (wb2ex_fwd       ),
        .ex2mem_bus      (ex2mem_bus      ),
        .br_bus          (br_bus          ),
        .data_sram_en    (data_sram_en    ),
        .data_sram_we    (data_sram_we    ),
        .data_sram_addr  (data_sram_addr  ),
        .data_sram_wdata (data_sram_wdata )
    );
    
    MEM 
    #(
        .EX2MEM_WD (EX2MEM_WD ),
        .MEM2WB_WD (MEM2WB_WD ),
        .MEM2EX_WD (MEM2EX_WD )
    )
    u_MEM(
    	.clk             (clk             ),
        .rst_n           (rst_n           ),
        .flush           (flush           ),
        .stall           (stall           ),
        .except_en       (except_en       ),
        .new_pc          (new_pc          ),
        .ex2mem_bus      (ex2mem_bus      ),
        .mem2wb_bus      (mem2wb_bus      ),
        .mem2ex_fwd      (mem2ex_fwd      ),
        .satp            (satp            ),
        .mstatus         (mstatus         ),
        .mie             (mie             ),
        .mtvec           (mtvec           ),
        .mtimecmp        (mtimecmp        ),
        .mtime           (mtime           ),
        .mscratch        (mscratch        ),
        .mepc            (mepc            ),
        .mcause          (mcause          ),
        .mip             (mip             ),
        .data_sram_rdata (data_sram_rdata )
    );
    
    WB 
    #(
        .MEM2WB_WD (MEM2WB_WD ),
        .WB2RF_WD  (WB2RF_WD  ),
        .WB2EX_WD  (WB2EX_WD  )
    )
    u_WB(
    	.clk               (clk               ),
        .rst_n             (rst_n             ),
        .flush             (flush             ),
        .stall             (stall             ),
        .mem2wb_bus        (mem2wb_bus        ),
        .wb2rf_bus         (wb2rf_bus         ),
        .wb2ex_fwd         (wb2ex_fwd         ),
        .debug_wb_pc       (debug_wb_pc       ),
        .debug_wb_inst     (debug_wb_inst     ),
        .debug_wb_rf_we    (debug_wb_rf_we    ),
        .debug_wb_rf_wnum  (debug_wb_rf_wnum  ),
        .debug_wb_rf_wdata (debug_wb_rf_wdata )
    );

    ctrl u_ctrl(
    	.rst_n         (rst_n         ),
        .except_en     (except_en     ),
        .stallreq_id   (stallreq_id   ),
        .stallreq_ex   (stallreq_ex   ),
        .stallreq_axi  (stallreq_axi  ),
        .flush         (flush         ),
        .stall         (stall         )
    );
    
    
    

endmodule
