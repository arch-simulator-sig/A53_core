`ifdef CONFIG_VERILATOR

    import "DPI-C" function void set_gpr_ptr(input xlen_t r[]);
               initial
                   set_gpr_ptr(regFile);
`endif

`ifdef CONFIG_VERILATOR

    import "DPI-C" function void set_pc_ptr(input xlen_t pc[]);
               xlen_t pc /*verilator forceable*/;
               assign pc = iDbgInfo.pc;
               initial
                   set_pc_ptr(pc);

               xlen_t rPC;

               always @(posedge clk)
               begin
                   rPC <= iDbgInfo.pc;
               end
               always @(iDbgInfo)
               begin
                   if(iDbgInfo.pc >= `PC_RST_VAL && rPC != iDbgInfo.pc)
                   begin
                       call_step(iDbgInfo.pc);
`ifdef CONFIG_ITRACE
                       itrace(`zext(iDbgInfo.inst));
`endif

                   end
               end

`endif