module btb
#(
    parameter BTBNUM = `BTB_LEN,
	parameter RASNUM = `RAS_LEN
)
(
    input             clk           ,
    input             reset         ,
    //from/to if
    input  [31:0]     fetch_pc      ,
    input             fetch_en      ,
    output [31:0]     ret_pc        ,
    output            taken         ,
    output            ret_en        ,
    output [ 4:0]     ret_index     ,
    //from id
    input             operate_en    ,
    input  [31:0]     operate_pc    ,
    input  [ 4:0]     operate_index ,
    input             pop_ras       ,
    input             push_ras      ,
    input             add_entry     ,
    input             delete_entry  ,
    input             pre_error     ,
    input             pre_right     ,
    input             target_error  ,
    input             right_orien   ,
    input  [31:0]     right_target  
);

/*
* btb_pc record all branch inst pc except jirl
* ras_pc only record jirl pc
*/
reg [29:0] btb_pc      [BTBNUM-1:0];
reg [29:0] btb_target  [BTBNUM-1:0];
reg [ 1:0] btb_counter [BTBNUM-1:0];

reg [BTBNUM-1:0] btb_valid;

reg [29:0] ras_pc [RASNUM-1:0];

reg [RASNUM-1:0] ras_valid;

reg [31:0] fetch_pc_r;
reg fetch_en_r;

reg [29:0] ras [7:0];
reg [ 3:0] ras_ptr;

wire [29:0] ras_top;

wire ras_full;
wire ras_empty;

wire [31:0] btb_match_rd;
wire [15:0] ras_match_rd;

wire btb_match;
wire ras_match;

wire [29:0] btb_match_target;
wire [ 1:0] btb_match_counter;
wire [ 4:0] btb_match_index;
wire [ 4:0] btb_random_index;

wire [ 3:0] ras_match_index;
wire [ 3:0] ras_random_index;

wire btb_all_entry_valid;
wire [4:0] btb_select_one_invalid_entry;
wire [4:0] btb_add_entry_index;
reg  [4:0] btb_add_entry_index_r;
wire [31:0] btb_add_entry_dec;

wire ras_all_entry_valid;
wire [3:0] ras_select_one_invalid_entry;
wire [3:0] ras_add_entry_index;

wire [31:0] btb_untaken_entry;
reg  [31:0] btb_untaken_entry_r;
wire [31:0] btb_untaken_entry_t;
reg         btb_add_entry_r;
wire [4:0]  btb_sel_one_untaken_entry;
wire        btb_has_one_untaken_entry;

//TODO:
reg [5:0] fcsr;


always @(posedge clk) begin
    if (reset)
        fetch_en_r <= 1'b0;
    else
        fetch_en_r <= fetch_en;

    if (fetch_en)
        fetch_pc_r <= fetch_pc;
end

always@(posedge clk) begin
    btb_untaken_entry_r <= btb_untaken_entry;
    btb_add_entry_r     <= 

end


endmodule