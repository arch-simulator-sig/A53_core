`include "defines.svh"

module ALU #(
        parameter WIDTH = `XLEN
    ) (
        input [`w(WIDTH)] iSrc1,
        input [`w(WIDTH)] iSrc2,

        output [`w(WIDTH)] oAddRslt,
        output [`w(WIDTH)] oSubRslt,
        output [`w(WIDTH)] oNotRslt,
        output [`w(WIDTH)] oAndRslt,
        output [`w(WIDTH)] oOrRslt ,
        output [`w(WIDTH)] oXorRslt,
        output [`w(WIDTH)] oSllRslt,
        output [`w(WIDTH)] oSrlRslt,
        output [`w(WIDTH)] oSraRslt,
        output oSltRslt,
        output oSltuRslt
    );

    wire [`w(WIDTH)] subSrc2 = ~iSrc2 + 1;
    wire signed [`w(WIDTH)] signedSrc1 = iSrc1;

    assign oAddRslt  = iSrc1 + iSrc2;
    assign oSubRslt  = iSrc1 + subSrc2;
    assign oNotRslt  = ~iSrc1;
    assign oAndRslt  = iSrc1 & iSrc2;
    assign oOrRslt   = iSrc1 | iSrc2;
    assign oXorRslt  = iSrc1 ^ iSrc2;
    assign oSllRslt  = iSrc1 << iSrc2;
    assign oSrlRslt  = iSrc1 >> iSrc2;
    assign oSraRslt  = signedSrc1 >>> iSrc2;
    assign oSltRslt = `msb(oSubRslt);
    assign oSltuRslt = (`msb(iSrc1) ^ `msb(iSrc2)) ? `msb(iSrc2) : `msb(oSubRslt);
    // When the first bit of the two operands is either both 1 or both 0, subtraction will not result in overflow. When one is 1 and the other is 0, the one with the first bit as 1, as an unsigned number, is obviously larger.

endmodule
