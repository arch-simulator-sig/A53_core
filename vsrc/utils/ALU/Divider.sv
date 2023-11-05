`include "defines.svh"

module Divider #(
        parameter WIDTH = `XLEN
    ) (
        input clk,
        nRst,
        input iValidIn,
        input iReadyOut,
        output oValid,
        input [`w(WIDTH)] iDivd,
        input [`w(WIDTH)] iDivr,
        input iSigned,
        output [`w(WIDTH)] oQuot,
        output [`w(WIDTH)] oRem
    );

    wire divdSign = iSigned & `msb(iDivd);
    wire divrSign = iSigned & `msb(iDivr);
    wire quotSign = divdSign ^ divrSign;
    wire remSign  = divdSign;

    logic [$clog2(WIDTH):0] rCnt;

    logic [`w(2*WIDTH)] rDivd;
    logic [`w(WIDTH+1)] rDivr;
    logic [`w(WIDTH)] rQuot;
    always @(posedge clk)
    begin
        if(nRst)
        begin
            if(iReadyOut)
            begin
                if (iValidIn)
                begin
                    rCnt <= '0;
                    rDivd <= {{WIDTH{1'b0}}, `stc(divdSign, iDivd)};
                    rDivr <= {1'b0, `stc(divrSign, iDivr)};
                    rQuot <= '0;
                end
                else
                begin
                    rCnt <= rCnt + 1;
                    rDivd <= {quotBit ? iterRslt : minuend, rDivd[`w(WIDTH-1)]} << 1;
                    rQuot <= rQuot | ({quotBit, {(WIDTH-1){1'b0}}} >> rCnt);
                end
            end
        end
    end

    wire [`w(WIDTH+1)] minuend = rDivd[`sel(2*WIDTH, WIDTH-1)];
    wire [`w(WIDTH+1)] iterRslt = minuend - rDivr;
    wire quotBit = ~iterRslt[WIDTH];

    assign oQuot = `stc(quotSign, rQuot);
    assign oRem = `stc(remSign, rDivd[`sel(2*WIDTH, WIDTH)]);
    assign oValid = (rCnt == WIDTH) && !iValidIn;

endmodule
