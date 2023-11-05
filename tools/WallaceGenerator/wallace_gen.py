import sys
from collections.abc import Callable

XLEN = 64
MUL_LEN = XLEN + 1
PART_NUM = int((MUL_LEN + 1) / 2)
PARTIAL = "partial"
READY = "oReady"
VALIDIN = "iValidIn"
REG_ENABLE = {1, 3, 5}
CSA22 = lambda in1, in2, sum, cout: f"HalfAdder adder{adder_cnt()} ({in1}, {in2}, {sum}, {cout});"
CSA32 = lambda in1, in2, cin, sum, cout: f"FullAdder adder{adder_cnt()} ({in1}, {in2}, {cin}, {sum}, {cout});"

REG = lambda layer: f"""
    always @(posedge clk)
    begin
        if({READY})
        begin
            r{layer} <= {layer};
        end
    end
"""


def adder_cnt() -> int:
    adder_cnt.count += 1
    return adder_cnt.count


adder_cnt.count = 0


def genBooth() -> list[list[int]]:
    rows = [set() for _ in range(PART_NUM)]  # set is unique
    columns: list[list[int]] = [list() for _ in range(MUL_LEN * 2)]  # list is ordered

    # booth gen simulation
    for i, row in enumerate(rows):
        lsb = i * 2
        msb = lsb + MUL_LEN
        row.update(range(lsb, msb + 1))
        if i == 0:
            row.add(0)
            row.update(range(msb + 1, msb + 4))
        else:
            row.add(lsb - 2)
            if i != PART_NUM - 1:
                row.update([msb + 1, msb + 2])
    # transpose
        for x in row:
            columns[x].append(i)
    return columns


def addColumn(_COLUMN: Callable[[int], str], column: list[int], _SUM: Callable[[int], str], sum: list[int],
              _COUT: Callable[[int], str], cout: list[int]) -> None:
    append: Callable[[list[int]], str] = lambda l: l.append(len(l))
    col_pop: Callable[[], str] = lambda: _COLUMN(column.pop(0))

    def sum_end() -> str:
        append(sum)
        return _SUM(len(sum))

    def cout_end() -> str:
        append(cout)
        return _COUT(len(cout))

    height = len(column)
    if height == 1:
        print(f"assign {sum_end()} = {col_pop()};")
    elif height == 2:
        print(CSA22(col_pop(), col_pop(), sum_end(), cout_end()))
    elif height >= 3:
        print(CSA32(col_pop(), col_pop(), col_pop(), sum_end(), cout_end()))
        if height > 3:
            addColumn(_COLUMN, column, _SUM, sum, _COUT, cout)


def addLayer(cur_n: int, cur: list[list[int]], insert_reg: bool) -> list[list[int]]:
    next: list[list[int]] = [list() for _ in range(len(cur) + 1)]
    _CUR = f"layer{str(cur_n)}" if cur_n != 0 else PARTIAL
    _NEXT = f"layer{str(cur_n + 1)}"

    if (insert_reg):
        print(REG(_CUR))
        _CUR = "r" + _CUR

    for i, col in enumerate(cur):
        addColumn(lambda n: f"{_CUR}[{n}][{i}]", col, lambda n: f"{_NEXT}[{n}][{i}]", next[i],
                  lambda n: f"{_NEXT}[{n}][{i + 1}]", next[i + 1])

    #remove empty rows
    while not next[-1]:
        next.pop()

    print(f"logic [`w({len(next)})] layer{cur_n + 1} [`w({len(max(next,key=len))})];")
    print(f"logic [`w({len(next)})] rlayer{cur_n + 1} [`w({len(max(next,key=len))})];")

    return next


def regValid(reg_enable: set[int]) -> None:
    valid = ["rValid" + str(_) for _ in reg_enable]
    print(f"""
    logic {", ".join(valid)};
    always @(posedge clk)
    begin
        if(oReady)
        begin
        {valid[0]} <= iValidIn;
        {''.join(['{} <= {};'.format(valid[i], valid[i-1]) for i, _ in enumerate(valid[1:],1)])}
        end
    end
    assign oValid = {valid[-1]};
    """)


code_file = sys.argv[1]

with open(code_file, 'w') as f:
    sys.stdout = f

    partial = genBooth()
    regValid(REG_ENABLE)

    layers = []
    layers.append(partial)
    for i, layer in enumerate(layers):
        if len(max(layer, key=len)) > 2:
            layers.append(addLayer(i, layer, i in REG_ENABLE))
        else:
            print(f"""
            wire [`w({len(layer)})] sum = layer{i}[0];
            wire [`w({len(layer)})] cout = layer{i}[1];
            assign rslt = {{sum + cout}}[`w({2 * XLEN})];
            """)