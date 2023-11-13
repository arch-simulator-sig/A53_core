`include "defines.v"
module lock_unit (
    input wire clk,
    input wire rst_n,
    input wire [5:0] stall,
    input wire [63:0] a,b,
    input wire mul_en, div_en,
    input wire stallreq_for_mul, stallreq_for_div,
    
    output wire [63:0] a_locked, b_locked,
    output wire mul_en_locked, div_en_locked
);
    reg first_enable;
    wire stallreq = stallreq_for_mul | stallreq_for_div;
    reg mul_en_musk, div_en_musk;
    reg [63:0] a_buffer, b_buffer;

    assign mul_en_locked = mul_en & mul_en_musk;
    assign div_en_locked = div_en & div_en_musk;
    assign a_locked = first_enable ? a : a_buffer;
    assign b_locked = first_enable ? b : b_buffer;

    always @ (posedge clk) begin
        if (!rst_n) begin
            a_buffer <= 0;
            b_buffer <= 0;
            mul_en_musk <= 1;
            div_en_musk <= 1;

            first_enable <= 1;
        end
        else if (mul_en & first_enable) begin
            a_buffer <= a;
            b_buffer <= b;
            mul_en_musk <= 0;
            div_en_musk <= 1;

            first_enable <= 0;
        end 
        else if (div_en & first_enable) begin
            a_buffer <= a;
            b_buffer <= b;
            mul_en_musk <= 1;
            div_en_musk <= 0;

            first_enable <= 0;
        end
        else if (!stallreq & (mul_en|div_en) & !first_enable & !stall[2]) begin
            a_buffer <= 0;
            b_buffer <= 0;
            mul_en_musk <= 1;
            div_en_musk <= 1;

            first_enable <= 1;
        end
        // else if (!first_enable) begin
        //     mul_en_locked <= 0;
        //     div_en_locked <= 0;
        // end
    end
endmodule