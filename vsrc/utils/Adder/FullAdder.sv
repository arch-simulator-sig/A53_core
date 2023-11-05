module FullAdder(
        input a,
        input b,
        input cin,
        output sum,
        output cout
    );

    assign {cout, sum} = a + b + cin;

endmodule
