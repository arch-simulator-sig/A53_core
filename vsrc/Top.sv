module Top (
        input clk,
        nRst
    );
    
    SimTop top(
        .clock(clk),
        .reset(~nRst)
    );

endmodule