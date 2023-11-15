`include "defines.v"
module decoder_64i (
    input [31:0] inst,
    
    // ex stage
    output wire [1:0] sel_src1,
    output wire sel_src2,
    output wire [4:0] rs1, rs2,
    output wire [63:0] imm,

    // alu part
    output wire [14:0] alu_op,

    // bru part
    output wire [7:0] bru_op,

    // lsu part
    output wire [6:0] lsu_op,

    // mul part
    output wire [4:0] mul_op,

    // div part
    output wire [3:0] div_op,

    // csr part
    output wire [3:0] csr_op,
    output wire [11:0] csr_addr,
    output wire csr_wdata_sel,
    output wire [31:0] csr_vec_l,

    output wire [3:0] sel_rf_res,

    // wb stage 
    output wire rf_we,
    output wire [4:0] rf_waddr,

    output wire oDbgHalt
);
    //defing slices
    wire [6:0] opcode, funct7;
    wire [15:0] opcode_l, funct7_l;
    wire [7:0] opcode_h, funct7_h;
    wire [4:0] rd, shamt5;
    wire [5:0] shamt6;
    wire [2:0] funct3;
    wire [7:0] funct3_d;
    wire [63:0] imm_i, imm_s, imm_b, imm_u, imm_j, zimm;

//define inst
    wire inst_sll, inst_slli, inst_srl, inst_srli, inst_sra, inst_srai;
    wire inst_add, inst_addi, inst_sub, inst_lui, inst_auipc;
    wire inst_xor, inst_xori, inst_or, inst_ori, inst_and, inst_andi;
    wire inst_slt, inst_slti, inst_sltu, inst_sltiu;
    wire inst_beq, inst_bne, inst_blt, inst_bge, inst_bltu, inst_bgeu;
    wire inst_jal, inst_jalr, inst_fence, inst_fence_i, inst_ecall, inst_ebreak, inst_mret;
    wire inst_csrrw, inst_csrrs, inst_csrrc, inst_csrrwi, inst_csrrsi, inst_csrrci;
    wire inst_lb, inst_lh, inst_lbu, inst_lhu, inst_lw;
    wire inst_sb, inst_sh, inst_sw;
    wire inst_lwu, inst_ld, inst_sd;
    wire inst_addiw, inst_slliw, inst_srliw, inst_sraiw;
    wire inst_addw, inst_subw, inst_sllw, inst_srlw, inst_sraw;
    // M extension
    wire inst_mul, inst_mulh, inst_mulhsu, inst_mulhu, inst_mulw;
    wire inst_div, inst_divu, inst_divuw, inst_divw;
    wire inst_rem, inst_remu, inst_remuw, inst_remw;
    // A extension
    wire inst_lr_w, inst_sc_w, inst_amoswap_w, inst_amoadd_w;
    wire inst_amoxor_w, inst_amoand_w, inst_amoor_w;
    wire inst_amomin_w, inst_amomax_w, inst_amominu_w, inst_amomaxu_w;
    wire inst_lr_d, inst_sc_d, inst_amoswap_d, inst_amoadd_d;
    wire inst_amoxor_d, inst_amoand_d, inst_amoor_d;
    wire inst_amomin_d, inst_amomax_d, inst_amominu_d, inst_amomaxu_d;

    //define alu operator
    wire op_and;
    wire op_or;
    wire op_xor;
    wire op_add;
    wire op_sub;
    wire op_slt;
    wire op_sltu;
    wire op_sll;
    wire op_srl;
    wire op_sra;
    wire op_addw;
    wire op_subw;
    wire op_sllw;
    wire op_srlw;
    wire op_sraw;

    // define div operation
    wire div;
    wire rem;
    wire signed_div;
    wire w_type;

    // define csr operation
    wire csr_we;
    wire op_csrrw;
    wire op_csrrs;
    wire op_csrrc;
    // wire csr_wdata_sel;

    assign opcode = inst[6:0];
    assign rd = inst[11:7];
    assign funct3 = inst[14:12];
    assign rs1 = inst[19:15];
    assign rs2 = inst[24:20];
    assign shamt5 = inst[24:20];
    assign shamt6 = inst[25:20];
    assign funct7 = inst[31:25]; 

    // sext(imm)
    assign imm_i = {{52{funct7[6]}}, funct7, rs2};
    assign imm_s = {{52{funct7[6]}}, funct7, rd};
    assign imm_b = {{52{funct7[6]}}, rd[0], funct7[5:0], rd[4:1], 1'b0};
    assign imm_u = {{32{inst[31]}}, inst[31:12], 12'b0};
    assign imm_j = {{44{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
    // usext(imm)
    assign zimm  = {59'b0, rs1};

    decoder_4_16 u0_decoder(
    	.in  (opcode[3:0]  ),
        .out (opcode_l )
    );

    decoder_3_8 u1_decoder(
    	.in  (opcode[6:4]  ),
        .out (opcode_h )
    );
    
    decoder_3_8 u2_decoder(
    	.in  (funct3  ),
        .out (funct3_d)
    );
    
    decoder_4_16 u3_decoder(
    	.in  (funct7[3:0]  ),
        .out (funct7_l )
    );
    
    decoder_3_8 u4_decoder(
    	.in  (funct7[6:4]  ),
        .out (funct7_h )
    );
    

    //decode inst
    assign inst_lui     = opcode_h[3'b011] & opcode_l[4'b0111];
    assign inst_auipc   = opcode_h[3'b001] & opcode_l[4'b0111];
    assign inst_jal     = opcode_h[3'b110] & opcode_l[4'b1111];
    assign inst_jalr    = opcode_h[3'b110] & opcode_l[4'b0111];

    assign inst_beq     = opcode_h[3'b110] & opcode_l[4'b0011] & funct3_d[3'b000];
    assign inst_bne     = opcode_h[3'b110] & opcode_l[4'b0011] & funct3_d[3'b001];
    assign inst_blt     = opcode_h[3'b110] & opcode_l[4'b0011] & funct3_d[3'b100];
    assign inst_bge     = opcode_h[3'b110] & opcode_l[4'b0011] & funct3_d[3'b101];
    assign inst_bltu    = opcode_h[3'b110] & opcode_l[4'b0011] & funct3_d[3'b110];
    assign inst_bgeu    = opcode_h[3'b110] & opcode_l[4'b0011] & funct3_d[3'b111];

    assign inst_lb      = opcode_h[3'b000] & opcode_l[4'b0011] & funct3_d[3'b000];
    assign inst_lh      = opcode_h[3'b000] & opcode_l[4'b0011] & funct3_d[3'b001];
    assign inst_lw      = opcode_h[3'b000] & opcode_l[4'b0011] & funct3_d[3'b010];
    assign inst_ld      = opcode_h[3'b000] & opcode_l[4'b0011] & funct3_d[3'b011];
    assign inst_lbu     = opcode_h[3'b000] & opcode_l[4'b0011] & funct3_d[3'b100];
    assign inst_lhu     = opcode_h[3'b000] & opcode_l[4'b0011] & funct3_d[3'b101];
    assign inst_lwu     = opcode_h[3'b000] & opcode_l[4'b0011] & funct3_d[3'b110];

    assign inst_sb      = opcode_h[3'b010] & opcode_l[4'b0011] & funct3_d[3'b000];
    assign inst_sh      = opcode_h[3'b010] & opcode_l[4'b0011] & funct3_d[3'b001];
    assign inst_sw      = opcode_h[3'b010] & opcode_l[4'b0011] & funct3_d[3'b010];
    assign inst_sd      = opcode_h[3'b010] & opcode_l[4'b0011] & funct3_d[3'b011];

    assign inst_addi    = opcode_h[3'b001] & opcode_l[4'b0011] & funct3_d[3'b000];
    assign inst_slti    = opcode_h[3'b001] & opcode_l[4'b0011] & funct3_d[3'b010];
    assign inst_sltiu   = opcode_h[3'b001] & opcode_l[4'b0011] & funct3_d[3'b011];
    assign inst_xori    = opcode_h[3'b001] & opcode_l[4'b0011] & funct3_d[3'b100];
    assign inst_ori     = opcode_h[3'b001] & opcode_l[4'b0011] & funct3_d[3'b110];
    assign inst_andi    = opcode_h[3'b001] & opcode_l[4'b0011] & funct3_d[3'b111];

    assign inst_slli    = opcode_h[3'b001] & opcode_l[4'b0011] & funct3_d[3'b001] & funct7_h[3'b000] & (~(|inst[28:26]));
    assign inst_srli    = opcode_h[3'b001] & opcode_l[4'b0011] & funct3_d[3'b101] & funct7_h[3'b000] & (~(|inst[28:26]));
    assign inst_srai    = opcode_h[3'b001] & opcode_l[4'b0011] & funct3_d[3'b101] & funct7_h[3'b010] & (~(|inst[28:26]));

    assign inst_addiw   = opcode_h[3'b001] & opcode_l[4'b1011] & funct3_d[3'b000];
    assign inst_slliw   = opcode_h[3'b001] & opcode_l[4'b1011] & funct3_d[3'b001] & funct7_h[3'b000] & funct7_l[4'b0000];
    assign inst_srliw   = opcode_h[3'b001] & opcode_l[4'b1011] & funct3_d[3'b101] & funct7_h[3'b000] & funct7_l[4'b0000];
    assign inst_sraiw   = opcode_h[3'b001] & opcode_l[4'b1011] & funct3_d[3'b101] & funct7_h[3'b010] & funct7_l[4'b0000];

    assign inst_add     = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b000] & funct7_h[3'b000] & funct7_l[4'b0000];
    assign inst_sub     = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b000] & funct7_h[3'b010] & funct7_l[4'b0000];
    assign inst_sll     = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b001] & funct7_h[3'b000] & funct7_l[4'b0000];
    assign inst_slt     = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b010] & funct7_h[3'b000] & funct7_l[4'b0000];
    assign inst_sltu    = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b011] & funct7_h[3'b000] & funct7_l[4'b0000];
    assign inst_xor     = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b100] & funct7_h[3'b000] & funct7_l[4'b0000];
    assign inst_srl     = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b101] & funct7_h[3'b000] & funct7_l[4'b0000];
    assign inst_sra     = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b101] & funct7_h[3'b010] & funct7_l[4'b0000];
    assign inst_or      = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b110] & funct7_h[3'b000] & funct7_l[4'b0000];
    assign inst_and     = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b111] & funct7_h[3'b000] & funct7_l[4'b0000];

    assign inst_addw    = opcode_h[3'b011] & opcode_l[4'b1011] & funct3_d[3'b000] & funct7_h[3'b000] & funct7_l[4'b0000];
    assign inst_subw    = opcode_h[3'b011] & opcode_l[4'b1011] & funct3_d[3'b000] & funct7_h[3'b010] & funct7_l[4'b0000];
    assign inst_sllw    = opcode_h[3'b011] & opcode_l[4'b1011] & funct3_d[3'b001] & funct7_h[3'b000] & funct7_l[4'b0000];
    assign inst_srlw    = opcode_h[3'b011] & opcode_l[4'b1011] & funct3_d[3'b101] & funct7_h[3'b000] & funct7_l[4'b0000];
    assign inst_sraw    = opcode_h[3'b011] & opcode_l[4'b1011] & funct3_d[3'b101] & funct7_h[3'b010] & funct7_l[4'b0000];

    assign inst_mul     = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b000] & funct7_h[3'b000] & funct7_l[4'b0001];
    assign inst_mulh    = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b001] & funct7_h[3'b000] & funct7_l[4'b0001];
    assign inst_mulhsu  = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b010] & funct7_h[3'b000] & funct7_l[4'b0001];
    assign inst_mulhu   = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b011] & funct7_h[3'b000] & funct7_l[4'b0001];
    assign inst_mulw    = opcode_h[3'b011] & opcode_l[4'b1011] & funct3_d[3'b000] & funct7_h[3'b000] & funct7_l[4'b0001];

    assign inst_div     = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b100] & funct7_h[3'b000] & funct7_l[4'b0001];
    assign inst_divu    = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b101] & funct7_h[3'b000] & funct7_l[4'b0001];
    assign inst_divuw   = opcode_h[3'b011] & opcode_l[4'b1011] & funct3_d[3'b101] & funct7_h[3'b000] & funct7_l[4'b0001];
    assign inst_divw    = opcode_h[3'b011] & opcode_l[4'b1011] & funct3_d[3'b100] & funct7_h[3'b000] & funct7_l[4'b0001];

    assign inst_rem     = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b110] & funct7_h[3'b000] & funct7_l[4'b0001];
    assign inst_remu    = opcode_h[3'b011] & opcode_l[4'b0011] & funct3_d[3'b111] & funct7_h[3'b000] & funct7_l[4'b0001];
    assign inst_remuw   = opcode_h[3'b011] & opcode_l[4'b1011] & funct3_d[3'b111] & funct7_h[3'b000] & funct7_l[4'b0001];
    assign inst_remw    = opcode_h[3'b011] & opcode_l[4'b1011] & funct3_d[3'b110] & funct7_h[3'b000] & funct7_l[4'b0001];    

    assign inst_lr_w        = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b010] & funct7_h[3'b000] & (funct7_l[4'b1000] | funct7_l[4'b1001] | funct7_l[4'b1010] | funct7_l[4'b1011]);
    assign inst_sc_w        = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b010] & funct7_h[3'b000] & (funct7_l[4'b1100] | funct7_l[4'b1101] | funct7_l[4'b1110] | funct7_l[4'b1111]);
    assign inst_amoswap_w   = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b010] & funct7_h[3'b000] & (funct7_l[4'b0100] | funct7_l[4'b0101] | funct7_l[4'b0110] | funct7_l[4'b0111]);
    assign inst_amoadd_w    = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b010] & funct7_h[3'b000] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);
    assign inst_amoxor_w    = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b010] & funct7_h[3'b001] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);
    assign inst_amoand_w    = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b010] & funct7_h[3'b011] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);
    assign inst_amoor_w     = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b010] & funct7_h[3'b010] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);
    assign inst_amomin_w    = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b010] & funct7_h[3'b100] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);
    assign inst_amomax_w    = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b010] & funct7_h[3'b101] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);
    assign inst_amominu_w   = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b010] & funct7_h[3'b110] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);
    assign inst_amomaxu_w   = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b010] & funct7_h[3'b111] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);

    assign inst_lr_d        = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b011] & funct7_h[3'b000] & (funct7_l[4'b1000] | funct7_l[4'b1001] | funct7_l[4'b1010] | funct7_l[4'b1011]);
    assign inst_sc_d        = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b011] & funct7_h[3'b000] & (funct7_l[4'b1100] | funct7_l[4'b1101] | funct7_l[4'b1110] | funct7_l[4'b1111]);
    assign inst_amoswap_d   = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b011] & funct7_h[3'b000] & (funct7_l[4'b0100] | funct7_l[4'b0101] | funct7_l[4'b0110] | funct7_l[4'b0111]);
    assign inst_amoadd_d    = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b011] & funct7_h[3'b000] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);
    assign inst_amoxor_d    = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b011] & funct7_h[3'b001] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);
    assign inst_amoand_d    = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b011] & funct7_h[3'b011] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);
    assign inst_amoor_d     = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b011] & funct7_h[3'b010] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);
    assign inst_amomin_d    = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b011] & funct7_h[3'b100] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);
    assign inst_amomax_d    = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b011] & funct7_h[3'b101] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);
    assign inst_amominu_d   = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b011] & funct7_h[3'b110] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);
    assign inst_amomaxu_d   = opcode_h[3'b010] & opcode_l[4'b1111] & funct3_d[3'b011] & funct7_h[3'b111] & (funct7_l[4'b0000] | funct7_l[4'b0001] | funct7_l[4'b0010] | funct7_l[4'b0011]);

    assign inst_csrrw   = opcode_h[3'b111] & opcode_l[4'b0011] & funct3_d[3'b001];
    assign inst_csrrs   = opcode_h[3'b111] & opcode_l[4'b0011] & funct3_d[3'b010];
    assign inst_csrrc   = opcode_h[3'b111] & opcode_l[4'b0011] & funct3_d[3'b011];
    assign inst_csrrwi  = opcode_h[3'b111] & opcode_l[4'b0011] & funct3_d[3'b101];
    assign inst_csrrsi  = opcode_h[3'b111] & opcode_l[4'b0011] & funct3_d[3'b110];
    assign inst_csrrci  = opcode_h[3'b111] & opcode_l[4'b0011] & funct3_d[3'b111];

    assign inst_ecall   = opcode_h[3'b111] & opcode_l[4'b0011] & ~(|inst[31:7]);
    assign inst_ebreak  = opcode_h[3'b111] & opcode_l[4'b0011] & ~(|inst[31:21]) & inst[20] & ~(|inst[19:7]);
    assign inst_mret    = opcode_h[3'b111] & opcode_l[4'b0011] & funct7_h[3'b001] & funct7_l[4'b1000] & (rs2==5'b00010) & ~(|inst[19:7]);

    
    //encode alu operator by inst type
    assign op_and = inst_and | inst_andi;
    assign op_or = inst_or | inst_ori;
    assign op_xor = inst_xor | inst_xori;
    assign op_add = inst_add | inst_addi | inst_lui | inst_auipc;
    assign op_sub = inst_sub;
    assign op_slt = inst_slt | inst_slti;
    assign op_sltu = inst_sltu | inst_sltiu;
    assign op_sll = inst_sll | inst_slli;
    assign op_srl = inst_srl | inst_srli;
    assign op_sra = inst_sra | inst_srai;
    assign op_addw = inst_addw | inst_addiw;
    assign op_subw = inst_subw;
    assign op_sllw = inst_sllw | inst_slliw;
    assign op_srlw = inst_srlw | inst_srliw;
    assign op_sraw = inst_sraw | inst_sraiw;

    // enable div operation
    assign div          = inst_div | inst_divu | inst_divuw | inst_divw;
    assign rem          = inst_rem | inst_remu | inst_remuw | inst_remw;
    assign signed_div   = inst_div | inst_divw | inst_rem | inst_remw;
    assign w_type       = inst_divuw | inst_divw | inst_remuw | inst_remw;

    // enable csr operation
    assign csr_we        = /*(rs1^0) &*/ (op_csrrw | op_csrrs | op_csrrc); // rs1==0 既可以是x0，也可以是zimm==0
    assign op_csrrw      = inst_csrrw | inst_csrrwi;
    assign op_csrrs      = inst_csrrs | inst_csrrsi;
    assign op_csrrc      = inst_csrrc | inst_csrrci;
    assign csr_addr      = inst[31:20];
    assign csr_wdata_sel = inst_csrrwi | inst_csrrsi | inst_csrrci;
    assign csr_vec_l     = {29'b0, inst_ecall, inst_ebreak, inst_mret};

    //encode for access mem
    wire data_ram_en;
    wire data_ram_we;
    wire [3:0] data_size_sel;
    wire data_unsigned;

    //make each operator into a bus, and transfer to other module
    assign alu_op = {
        op_and, op_or, op_xor, op_add, op_sub, op_slt,
        op_sltu, op_sll, op_srl, op_sra, op_addw, op_subw, 
        op_sllw, op_srlw, op_sraw
    };

    assign bru_op = {
        inst_jal, inst_jalr, inst_beq, inst_bne,
        inst_blt, inst_bge, inst_bltu, inst_bgeu
    };

    assign lsu_op = {
        data_ram_en, data_ram_we, data_size_sel, data_unsigned
    };

    assign mul_op = {
        inst_mul, inst_mulh, inst_mulhu, inst_mulhsu, inst_mulw
    };

    assign div_op = {
        div, rem, signed_div, w_type
    };

    assign csr_op = {
        csr_we, op_csrrw, op_csrrs, op_csrrc
    };

    // pc to src1
    assign sel_src1[0] = inst_auipc;
    // 0   to src1
    assign sel_src1[1] = inst_lui;
    // rs1  to src1 
    // assign sel_src1[2] = 

    // imm to src2
    assign sel_src2 =   inst_lui | inst_auipc | inst_lb | inst_lh | inst_lw | inst_ld | inst_lbu | inst_lhu | inst_lwu |
                        inst_sb | inst_sh | inst_sw | inst_sd | inst_addi | inst_addiw | inst_slti | inst_sltiu | inst_xori | 
                        inst_ori | inst_andi | inst_slli | inst_slliw | inst_srli | inst_srliw | inst_srai | inst_sraiw;
    // rs2 to src2
    // assign sel_src2[1] =



    wire [7:0] sel_imm;
    // I
    assign sel_imm[0] = inst_jalr | inst_lb | inst_lh | inst_lw | inst_ld | inst_lbu | inst_lhu | inst_lwu |
                        inst_addi | inst_addiw | inst_slti | inst_sltiu | inst_xori | inst_ori | inst_andi;
    // S
    assign sel_imm[1] = inst_sb | inst_sh | inst_sw | inst_sd;
    // B
    assign sel_imm[2] = inst_beq | inst_bne | inst_blt | inst_bge | inst_bltu | inst_bgeu;
    // U
    assign sel_imm[3] = inst_lui | inst_auipc;
    // J
    assign sel_imm[4] = inst_jal;
    // shamt5
    assign sel_imm[5] = inst_slliw | inst_srliw | inst_sraiw;
    // shamt6
    assign sel_imm[6] = inst_slli | inst_srli | inst_srai;
    // zimm
    assign sel_imm[7] = inst_csrrwi | inst_csrrsi | inst_csrrci;

    assign imm  = sel_imm[0] ? imm_i 
                : sel_imm[1] ? imm_s
                : sel_imm[2] ? imm_b
                : sel_imm[3] ? imm_u
                : sel_imm[4] ? imm_j 
                : sel_imm[5] ? {59'b0, shamt5} 
                : sel_imm[6] ? {58'b0, shamt6} 
                : sel_imm[7] ? zimm : 64'b0;



// lsu part begin
    assign data_ram_en =  inst_lb | inst_lbu | inst_lh | inst_lhu | inst_lw | inst_lwu | inst_ld 
                        | inst_sb | inst_sh | inst_sw | inst_sd;
    assign data_ram_we = inst_sb | inst_sh | inst_sw | inst_sd;

    // byte
    assign data_size_sel[0] = inst_lb | inst_lbu | inst_sb;
    // half word
    assign data_size_sel[1] = inst_lh | inst_lhu | inst_sh;
    // word
    assign data_size_sel[2] = inst_lw | inst_lwu | inst_sw;
    // double word
    assign data_size_sel[3] = inst_ld | inst_sd;
    assign data_unsigned = inst_lbu | inst_lhu | inst_lwu;
// lsu part end



    // rf_res from bru
    assign sel_rf_res[0] = inst_jal | inst_jalr;
    // rf_res from lsu
    assign sel_rf_res[1] = inst_lb | inst_lh | inst_lw | inst_ld | inst_lbu | inst_lhu | inst_lwu;
    // rf_res from csr
    assign sel_rf_res[2] = inst_csrrw | inst_csrrwi | inst_csrrs | inst_csrrsi | inst_csrrc | inst_csrrci;
    // rf_res from m module
    assign sel_rf_res[3] = inst_mul | inst_mulh | inst_mulhu | inst_mulhsu | inst_mulw | inst_div | inst_divu | 
                           inst_rem | inst_remu | inst_divw | inst_divuw | inst_remw | inst_remuw; 

    assign rf_we =  inst_lui | inst_auipc | inst_jal | inst_jalr |
                    inst_lb | inst_lh | inst_lw | inst_ld | inst_lbu | inst_lhu | inst_lwu |
                    inst_addi | inst_addiw | inst_slti | inst_sltiu | inst_xori | 
                    inst_ori | inst_andi | inst_slli | inst_slliw | inst_srli | inst_srliw | inst_srai | inst_sraiw |
                    inst_add | inst_addw | inst_sub | inst_subw | inst_sll | inst_sllw | inst_slt | inst_sltu |
                    inst_xor | inst_srl | inst_srlw | inst_sra | inst_sraw | inst_or | inst_and |
                    // inst_fence | inst_fence_i | inst_ecall | inst_ebreak |
                    inst_mul | inst_mulh | inst_mulhu | inst_mulhsu | inst_mulw | 
                    inst_div | inst_divu | inst_rem | inst_remu | inst_divw | inst_divuw | inst_remw | inst_remuw |
                    inst_csrrw | inst_csrrs | inst_csrrc | inst_csrrwi | inst_csrrsi | inst_csrrci;
    assign rf_waddr = rd;

endmodule
