`ifndef __DEFINES_SVH__
`define __DEFINES_SVH__

`include "config_generated.svh"

`define sel(_hi, _lo) ((_hi)-1):(_lo)

`define w(_width) `sel(_width, 0)

`define b(_signal) `w($bits(_signal))

`define _msb(_signal, _width) _signal[(_width)-1]
`define msb(_signal) `_msb(_signal, $bits(_signal))

`define byte(_b) (8*(_b))

`define selbyte(_hi, _lo) `sel(`byte(_hi), `byte(_lo))

`define _ZEXT(_signal, _width, _target_width) {{((_target_width)-(_width)){1'b0}}, _signal[`w(_width)]}
`define ZEXT(_signal, _width) `_ZEXT(_signal, _width, `XLEN)
`define _zext(_signal, _target_width) {{((_target_width)-$bits(_signal)){1'b0}}, _signal}
`define zext(_signal) `_zext(_signal, `XLEN)

`define _SEXT(_signal, _width, _target_width) {{((_target_width)-(_width)){_signal[(_width)-1]}}, _signal[`w(_width)]}
`define SEXT(_signal, _width) `_SEXT(_signal, _width, `XLEN)
`define _sext(_signal, _target_width) {{((_target_width)-$bits(_signal)){`msb(_signal)}}, _signal}
`define sext(_signal) `_sext(_signal, `XLEN)

`define if(_cond, _signal) ({$bits(_signal){_cond}}) & (_signal)

`define tc(_signal) (~(_signal)+1)

`define stc(_sign, _signal) (_sign ? `tc(_signal) : _signal)

        ////////////////////////////////////////////////////////////////////////////////

typedef logic [`w(2)] uint2_t;
typedef logic [`w(3)] uint3_t;
typedef logic [`w(8)] uint8_t;
typedef uint8_t byte_t;
typedef logic [`w(9)] uint9_t;
typedef logic [`w(12)] uint12_t;
typedef logic [`w(32)] uint32_t;

`define XLEN 64
typedef logic [`w(`XLEN)] xlen_t;

`define MXLEN `XLEN
typedef logic [`w(`MXLEN)] mxlen_t;

`define WORD 32
typedef logic [`w(`WORD)] word_t;

`define ADDR_LEN `WORD

`define INST_LEN 32 // the last two bits of the 32-bit insts is consistently b11
typedef logic [`w(`INST_LEN)] inst_t;

`define REG_CNT 32

`define i(_bit) ((_bit))
`define ir(_hi, _lo) `i(_hi):`i(_lo)

`define OPCODE_LEN 5

`define REG_IDX_LEN 5
typedef logic [`w(`REG_IDX_LEN)] gprIdx_t;

`define FUNCT3_LEN 3

`define FUNCT7_LEN 7

`define PC_RST_VAL `XLEN'h80000000

`define ALU_OP_LEN 4
typedef logic [`w(`ALU_OP_LEN)] aluOp_t;
// ALU control signals
typedef enum aluOp_t {
            ALU_NOP    = `ALU_OP_LEN'd0,
            ALU_ADD    = `ALU_OP_LEN'd1,
            ALU_SUB    = `ALU_OP_LEN'd2,
            ALU_NOT    = `ALU_OP_LEN'd3,
            ALU_AND    = `ALU_OP_LEN'd4,
            ALU_OR     = `ALU_OP_LEN'd5,
            ALU_XOR    = `ALU_OP_LEN'd6,
            ALU_SLL    = `ALU_OP_LEN'd7,
            ALU_SRL    = `ALU_OP_LEN'd8,
            ALU_SRA    = `ALU_OP_LEN'd9,
            ALU_SLT    = `ALU_OP_LEN'd10,
            ALU_MULL   = `ALU_OP_LEN'd11,
            ALU_MULH   = `ALU_OP_LEN'd12,
            ALU_MULHSU = `ALU_OP_LEN'd13,
            ALU_DIV    = `ALU_OP_LEN'd14,
            ALU_REM    = `ALU_OP_LEN'd15
        } ALU_OP;

// mul
`define MUL_LEN (`XLEN+1)

`define BRU_OP_LEN 3
typedef logic [`w(`BRU_OP_LEN)] bruOp_t;
// BRU control signals
typedef enum bruOp_t {
            BRU_JAL  = `BRU_OP_LEN'd0,
            BRU_JALR = `BRU_OP_LEN'd1,
            BRU_EQ   = `BRU_OP_LEN'd2,
            BRU_GE   = `BRU_OP_LEN'd3,
            BRU_GEU  = `BRU_OP_LEN'd4,
            BRU_LT   = `BRU_OP_LEN'd5,
            BRU_LTU  = `BRU_OP_LEN'd6,
            BRU_NE   = `BRU_OP_LEN'd7
        } BRU_OP;

`define WIDTH_SUF_LEN 2
typedef logic [`w(`WIDTH_SUF_LEN)] width_t;
// width = 1 << width_suf
`define WIDTH_SUF_B 0
`define WIDTH_SUF_H 1
`define WIDTH_SUF_W 2
`define WIDTH_SUF_D 3
`define WSUF(_type) `WIDTH_SUF_LEN'd`WIDTH_SUF_``_type
`define WIDTH(_type) (7'b1 << (`WIDTH_SUF_``_type))
`define WIDTH_SEL(_signal, _type, _byte) _signal[`selbyte(_byte+`WIDTH(_type), _byte)]

`include "CSR.svh"
`include "ports.svh"

`endif
