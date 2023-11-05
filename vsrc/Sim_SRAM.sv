`include "defines.svh"
`include "DPI-C.svh"

module Sim_SRAM (
        input clk,
        nRst,
        
        input SramReq_t iReq,
        output SramRsp_t oRsp
    );

    typedef logic [2:0] state_t;
    typedef enum state_t {
                IDLE   = 3'd0,
                ADDROK = 3'd1,
                DATPRE = 3'd2,
                DATOK  = 3'd4
            } STATE;

    state_t rState;
    state_t rState_f;

    always @(negedge clk)
    begin
        if (nRst)
        begin
            rState <= rState_f;
        end
        else
        begin
            rState <= IDLE;
        end
    end

    always_comb
    begin
        if (nRst)
        begin
            case (rState)
                IDLE, DATOK:
                    if (iReq.req)
                    begin
                        rState_f = ADDROK;
                    end
                    else
                    begin
                        rState_f = IDLE;
                    end
                ADDROK:
                    rState_f = DATPRE;
                DATPRE:
                    rState_f = DATOK;
                default:
                    rState_f = IDLE;
            endcase
        end
        else
        begin
            rState_f = IDLE;
        end
    end

    wire addrOK = rState == ADDROK;
    assign oRsp.addrOK = addrOK;
    wire datOK  = rState == DATOK;
    assign oRsp.datOK = datOK;

    xlen_t rdDat;
    assign oRsp.rdDat = `if(datOK, rdDat);

    SramReq_t rReq;

    always @(posedge clk)
    begin
        if(rState == ADDROK)
        begin
            rReq <= iReq;
        end
        if (rState == DATPRE)
        begin
            if (rReq.wrOrRd)
            begin
                pmem_write(`zext(rReq.addr), rReq.wrDat, rReq.wrStrb);
            end
            else
            begin
                pmem_read(`zext(rReq.addr), rdDat);
            end
        end
    end
`undef MAP

endmodule
