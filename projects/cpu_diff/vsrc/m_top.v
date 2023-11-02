`include "defines.v"
module m_top(
    input wire clk,
    input wire rst_n,
    input wire [5:0] stall,
    output wire stallreq,

    input wire [4:0] mul_op, // mul, mulh, mulhu, mulhsu, mulw
    input wire [3:0] div_op, // div rem signed word-type

    input wire [63:0] a, b,
    output wire [63:0] result
);

// common
wire stallreq_for_mul, stallreq_for_div;
wire sign_flag;
wire inst_mul, inst_mulh, inst_mulhu, inst_mulhsu, inst_mulw;
wire div, rem, signed_div, w_type;
wire [63:0] src_a, src_b, result_h, result_l, quotient, remainder;

assign {inst_mul,inst_mulh,inst_mulhu,inst_mulhsu,inst_mulw} = mul_op;
assign {div,rem,signed_div,w_type} = div_op;

wire mul_en;
wire div_en;
assign mul_en = |mul_op;
assign div_en = div | rem;

assign sign_flag = a[63]^b[63];
assign src_a = w_type & ~signed_div ? {32'b0,a[31:0]}
             : w_type &  signed_div ? {{32{a[31]}},a[31:0]}
             : inst_mul | inst_mulhu | inst_mulw | ~signed_div ? a
             : inst_mulhsu | inst_mulh | signed_div ? (a[63] ? {1'b0,~a[62:0]+1'b1} : a) 
             : 64'b1;
assign src_b = w_type & ~signed_div ? {32'b0,b[31:0]}
             : w_type &  signed_div ? {{32{b[31]}},b[31:0]}
             : inst_mul | inst_mulhu | inst_mulhsu | inst_mulw | ~signed_div ? b
             : inst_mulh | signed_div ? (b[63] ? {1'b0,~b[62:0]+1'b1} : b)
             : 64'b1;

wire [63:0] a_locked, b_locked;
wire mul_en_locked, div_en_locked;
lock_unit u_lock_unit(
    .clk              (clk              ),
    .rst_n            (rst_n            ),
    .stall            (stall            ),
    .a                (src_a            ),
    .b                (src_b            ),
    .mul_en           (mul_en           ),
    .div_en           (div_en           ),
    .stallreq_for_mul (stallreq_for_mul ),
    .stallreq_for_div (stallreq_for_div ),
    .a_locked         (a_locked         ),
    .b_locked         (b_locked         ),
    .mul_en_locked    (mul_en_locked    ),
    .div_en_locked    (div_en_locked    )
);


// mul 
multiplier u_multiplier(
    .clk       (clk       ),
    .rst_n     (rst_n     ),
    .stallreq  (stallreq_for_mul),
    .in_valid  (mul_en_locked    ),
    // .out_valid (out_valid ),
    .a         (a_locked     ),
    .b         (b_locked     ),
    .result_h  (result_h  ),
    .result_l  (result_l  )
);

wire [127:0] unsigend_mul_result, signed_mul_result;
assign unsigend_mul_result = {result_h,result_l};
assign signed_mul_result = sign_flag ? {sign_flag,~unsigend_mul_result[126:0]+1'b1} : {sign_flag,unsigend_mul_result[126:0]};


// div
divider u_divider(
    	.clk       (clk       ),
        .rst_n     (rst_n     ),
        .stallreq  (stallreq_for_div),
        .in_valid  (div_en_locked    ),
        // .out_valid (out_valid ),
        .a         (a_locked     ),
        .b         (b_locked     ),
        .quotient  (quotient  ),
        .remainder (remainder )
    );

assign stallreq = stallreq_for_mul | stallreq_for_div;
assign result = inst_mul    ? result_l :
                inst_mulh   ? signed_mul_result[127:64] :
                inst_mulhu  ? result_h :
                inst_mulhsu ? signed_mul_result[127:64] :
                inst_mulw   ? {{32{result_l[31]}},result_l[31:0]} :
                div & ~signed_div & ~w_type ? quotient :
                div &  signed_div & ~w_type ? sign_flag ? {sign_flag, ~quotient[62:0]+1'b1} : {sign_flag, quotient[62:0]} :
                rem & ~signed_div & ~w_type ? remainder :
                rem &  signed_div & ~w_type ? sign_flag ? {sign_flag, ~remainder[62:0]+1'b1} : {sign_flag, remainder[62:0]} :
                div & ~signed_div &  w_type ? {{32{quotient[31]}},quotient[31:0]} :
                div &  signed_div &  w_type ? sign_flag ? {{32{sign_flag}},{sign_flag,~quotient[30:0]+1'b1}} : {{32{sign_flag}}, {sign_flag, quotient[30:0]}} :
                rem & ~signed_div &  w_type ? {{32{remainder[31]}},remainder[31:0]} :
                rem &  signed_div &  w_type ? sign_flag ? {{32{sign_flag}},{sign_flag,~remainder[30:0]+1'b1}} : {{32{sign_flag}}, {sign_flag, remainder[30:0]}} :
                64'b0;


endmodule