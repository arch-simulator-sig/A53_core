`include "defines.v"
module ctrl(
    input wire rst_n,
    input wire except_en,
    input wire stallreq_id,
    input wire stallreq_ex,
    input wire stallreq_axi,
    output reg flush,
    output reg [`StallBus-1:0] stall
);
    //stall[0] --?
    //stall[1] --?
    //stall[2] --id
    //stall[3]
    //stall[4]
    //stall[5]
    always @ (*) begin
        if (!rst_n) begin
            flush = 0;
            stall = `StallBus'b0;
        end
        else if (stallreq_axi) begin
            flush = 0;
            stall = `StallBus'b111111;
        end
        else if (except_en) begin
            flush = 1;
            stall = `StallBus'b0;
        end
        //id段发生暂停，此时id及之前暂停
        else if (stallreq_id) begin
            flush = 0;
            stall = `StallBus'b000111;
        end
        else if (stallreq_ex) begin
            flush = 0;
            stall = `StallBus'b111111;
        end
        else begin
            flush = 0;
            stall = `StallBus'b0;
        end
    end
endmodule
