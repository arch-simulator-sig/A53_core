`include "defines.svh"

module BoothGenerator #(
        WIDTH = 64,
        LSB   = 64
    ) (
        input [2:0] iMulc,
        input [`w(MUL_LEN)] iMulr,
        input iCarryPre,

        output [`w(MUL_LEN*2)] oPart,
        output oCarry
    );
    localparam MUL_LEN = WIDTH + 1;
    localparam MSB = LSB + MUL_LEN;

    wire neg1c =  iMulc[2] & (iMulc[1] ^  iMulc[0]);
    wire neg2c =  iMulc[2] & ~iMulc[1] & ~iMulc[0];
    wire pos1c = ~iMulc[2] & (iMulc[1] ^  iMulc[0]);
    wire pos2c = ~iMulc[2] &  iMulc[1] &  iMulc[0];

    assign oCarry = neg1c | neg2c;

    wire mulrSign = `msb(iMulr);
    wire partSign = `if(neg1c || neg2c, ~mulrSign) | `if(pos1c || pos2c, mulrSign);
    if(LSB == 0)
    begin
        assign oPart[0] = `if(neg1c, ~iMulr[0]) | `if(pos1c, iMulr[0]) | neg2c;
        assign oPart[MSB+3:MSB+1] = {~partSign, {2{partSign}}};
    end
    else // LSB is even
    begin
        assign oPart[LSB-2] = iCarryPre;
        assign oPart[LSB]   = `if(neg1c, ~iMulr[0]) | `if(pos1c, iMulr[0]) | neg2c;
        if(LSB != MUL_LEN-1) // not the last row
        begin
            assign oPart[MSB+2] = 1'b1;
            assign oPart[MSB+1] = ~partSign;
        end
    end
    for(genvar i = 1; i < MUL_LEN; i++)
    begin
        assign oPart[LSB+i] =
               `if(neg1c, ~iMulr[i  ]) |
               `if(neg2c, ~iMulr[i-1]) |
               `if(pos1c,  iMulr[i  ]) |
               `if(pos2c,  iMulr[i-1]);
    end
    assign oPart[MSB] = partSign;// sign extend

endmodule
