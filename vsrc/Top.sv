`include "defines.svh"

module Top (
        input clk,
        nRst
    );

    SramRsp_t rsp_SRAM;
    SramReq_t req_SRAM;

    Core CPU (
             .clk,
             .nRst,
             .iRsp_SRAM(rsp_SRAM),
             .oReq_SRAM(req_SRAM)
         );

    Sim_SRAM U_SRAM (
                 .clk,
                 .nRst,
                 .iReq(req_SRAM),
                 .oRsp(rsp_SRAM)
             );

endmodule
