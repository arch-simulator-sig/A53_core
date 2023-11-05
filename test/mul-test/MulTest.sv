`include "defines.svh"

module MulTest #(
        WIDTH = 8
    ) (
        input clk,
        nRst,
        input [`w(WIDTH+1)] iMulc,
        input [`w(WIDTH+1)] iMulr,
        output [`w(WIDTH*2)] oRslt,
        output oRsltOK
    );
    
    logic mulValid;
    logic rMulBusy;
    wire mulReq = !rMulBusy;

    always @(posedge clk)
    begin
        if(nRst)
        begin
            if(mulValid)
            begin
                rMulBusy <= '0;
            end
            else
            begin
                rMulBusy <= 1'b1;
            end
        end
        else
        begin
            rMulBusy <= '0;
        end
    end
    
    logic [`w(WIDTH)] rsltHi;
    logic [`w(WIDTH)] rsltLo;

    Multiplier #(WIDTH) U_Multiplier (
                   .clk,
                   .nRst,
                   .iValidIn(mulReq),
                   .iReadyOut(1),
                   .oValid(mulValid),
                   .oReady(oRsltOK),
                   .iMulc,
                   .iMulr,
                   .oRsltHi(rsltHi),
                   .oRsltLo(rsltLo)
               );

    assign oRslt = {rsltHi, rsltLo};

endmodule

