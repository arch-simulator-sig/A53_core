`include "defines.svh"

module Multiplier #(
        WIDTH = `XLEN
    ) (
        input  clk,
        nRst,
        input  iValidIn,
        input  iReadyOut,
        output oValid,
        output oReady,

        input [`w(MUL_LEN)] iMulc,
        input [`w(MUL_LEN)] iMulr,
        output [`w(WIDTH)] oRsltHi,
        output [`w(WIDTH)] oRsltLo
    );
    localparam MUL_LEN = WIDTH + 1;

`ifdef CONFIG_MUL_VERIFY

    logic [`w(2*WIDTH)] rRslt1, rRslt2, rRslt3;
    logic rValid1, rValid2, rValid3;

    assign oValid = rValid3;
    assign oReady = !oValid || iReadyOut;

    always @(posedge clk)
    begin
        if(oReady)
        begin
            rValid1 <= iValidIn;
            rValid2 <= rValid1;
            rValid3 <= rValid2;
            rRslt2 <= rRslt1;
            rRslt3 <= rRslt2;
            rRslt1 <= rslt[`w(2*WIDTH)];
        end
    end

    wire signed [`w(MUL_LEN)] mulc = iMulc;
    wire signed [`w(MUL_LEN)] mulr = iMulr;
    wire signed [`w(2*MUL_LEN)] rslt = mulc * mulr;
    assign {oRsltHi, oRsltLo} = rRslt3;

`else

    localparam PART_NUM = (MUL_LEN + 1) / 2; // 33
    logic [`w(MUL_LEN*2)] partial [`w(PART_NUM)];
    logic [`w(PART_NUM)] carry;
    // we don't need to deal with the last carry since it is constantly 0
    // the most significant two bits must be 0x or 11
    // thus the three bits used to produce the last partial products are 00x or 111
    // definitely not yielding a carry

    // genertae partial products
    BoothGenerator #(WIDTH, 0) U0_BoothGen (
                       .iMulc({iMulc[1:0], 1'b0}),
                       .iMulr,
                       .iCarryPre(0),
                       .oPart(partial[0]),
                       .oCarry(carry[0])
                   );
    for (genvar i = 1; i < PART_NUM - 1; i++)
    begin
        BoothGenerator #(WIDTH, 2 * i) U_BoothGen (
                           .iMulc(iMulc[2*i+1:2*i-1]),
                           .iMulr,
                           .iCarryPre(carry[i-1]),
                           .oPart(partial[i]),
                           .oCarry(carry[i])
                       );
    end
    BoothGenerator #(WIDTH, 2 * (PART_NUM - 1)) UM_BoothGen (
                       .iMulc({iMulc[2*PART_NUM-2], iMulc[2*PART_NUM-2:2*PART_NUM-3]}),
                       .iMulr,
                       .iCarryPre(carry[PART_NUM-2]),
                       .oPart(partial[PART_NUM-1]),
                       .oCarry(carry[PART_NUM-1])
                   );

    logic [`w(WIDTH*2)] rslt;
`include "wallace_generated.sv"

    assign {oRsltHi, oRsltLo} = rslt;

    assign oReady = !oValid || iReadyOut;

`endif

endmodule
