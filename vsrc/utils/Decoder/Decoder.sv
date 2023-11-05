module Decoder #(
        parameter IN_WIDTH = 5
    ) (
        input [IN_WIDTH-1:0] in,
        output [(1 << IN_WIDTH)-1:0] out
    );
    localparam OUT_WIDTH = 1 << IN_WIDTH;

    for(genvar i = 0 ; i < OUT_WIDTH; i++)
    begin
        assign out[i] = (in == i);
    end

endmodule
