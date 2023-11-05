import pandas as pd
import os
import sys


class Inst(object):

    class SignalMatch(str):

        def onebitCheck(self, signal, prefix: str = "& ", suffix: str = " "):
            return self.__class__(self + prefix +
                                  (signal if codes[signal] == "1" else "~" + signal if codes[signal] == "0" else "1'b1") +
                                  suffix)

        def onehotCheck(self, signal, prefix: str = "&", suffix: str = ""):

            original_code = codes[signal]
            if all(ch == "?" for ch in original_code):
                ret = "1'b1"
            else:
                codes_expanded: list[str] = []

                def expandQmark(code: str):
                    if "?" in code:
                        expandQmark(code.replace("?", "0", 1))
                        expandQmark(code.replace("?", "1", 1))
                    else:
                        codes_expanded.append(code)

                expandQmark(codes[signal])
                ret = " | ".join(map(lambda c: f"{signal}OneHot[{len(c)}'b{c}]", codes_expanded))
            return self.__class__(f"{self}{prefix} ({ret}) {suffix}")

    def __init__(self, name: str, type: str) -> None:
        self.name = name
        self.signal = self.name + "Dec"
        self.type = type
        onehotCheck = lambda signal: "1'b1" if all(
            ch == "?" for ch in codes[signal]) else lambda signal: signal + f"OneHot[{len(codes[signal])}'b{codes[signal]}]"
        decode_signal = self.SignalMatch(f"wire {self.signal} =")
        self.decode_signal = decode_signal.onehotCheck(
            "funct7", prefix=" ").onehotCheck("funct12_10").onehotCheck("funct3").onehotCheck("opcode", suffix=";\n")

    def genDecode(self, codes: dict):

        return


class MultiBitsCtlSignal(object):

    def __init__(self, content: str) -> None:
        self.content = content
        split = content.split("\n")
        self.name = split[0]
        self.type = split[1]
        self.pattern = split[2]
        self.inst_signals = [f"assign oDecode.{split[0]} =\n"]


class OneBitCtlSignal(object):

    def __init__(self, name: str) -> None:
        self.name = name
        self.inst_signals = [f"assign oDecode.{name} =\n"]


# open xlsx file
sheet_file = sys.argv[1]
code_file = sys.argv[2]
header_file = sys.argv[3]
df = pd.read_excel(sheet_file, sheet_name="decode", dtype="str").fillna("")
data = df.to_dict(orient="records")

# decode insts
header = df.columns.to_list()
onebit_index = header.index("OneBitControlSignals")
multibits_signals = list(map(MultiBitsCtlSignal, header[header.index("MultiBitsControlSignals") + 1:onebit_index]))
# print(header[onebit_index + 1:])
onebit_signals = list(map(OneBitCtlSignal, header[onebit_index + 1:]))

with open(header_file, "w", encoding="utf-8") as f:
    sys.stdout = f
    for signal in multibits_signals:
        print(f"{signal.type} {signal.name};")
    for signal in onebit_signals:
        print(f"logic {signal.name};")
    sys.stdout = sys.__stdout__

inst_signals_code = []
type_signals = dict(map(lambda type: (type, [f"assign oType{type} =\n"]), ("R", "I", "S", "B", "U", "J", "NONE")))
for line in data:
    name = line["inst"]
    type = line["type"]
    codes = dict(map(lambda field: (field, line[field]), ("opcode", "funct3", "funct7", "funct12_10")))
    inst = Inst(name, type)

    inst_signals_code.append(inst.decode_signal)

    # generate control signals
    for signal in multibits_signals:
        if line[signal.content] != "":
            signal.inst_signals.append(f"`if({inst.signal}, {signal.pattern.format(line[signal.content]).upper()}) |\n")

    for signal in onebit_signals:
        if line[signal.name] == "1":
            signal.inst_signals.append(inst.signal + "|\n")

    for type in type_signals:
        if inst.type == type:
            type_signals[type].append(inst.signal + " |\n")

if_suffix = "'0;\n"
code_join = lambda stmt: "".join(stmt) + if_suffix
type_signals_code = list(map(code_join, type_signals.values()))
multibits_signals_code = []
onebit_signals_code = []
for signal in multibits_signals:
    multibits_signals_code.append(code_join(signal.inst_signals))
for signal in onebit_signals:
    onebit_signals_code.append(code_join(signal.inst_signals))

# write file
code = "".join(map("".join, (inst_signals_code, type_signals_code, multibits_signals_code, onebit_signals_code)))

with open(code_file, "w", encoding="utf-8") as f:
    print(code, file=f)
print("IDU generated")
