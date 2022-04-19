// Generator : SpinalHDL v1.6.1    git head : 3bf789d53b1b5a36974196e2d591342e15ddf28c
// Component : Pc
// Git hash  : 0525e73eb5472b586b775db09c699e2bed04aa81

`timescale 1ns/1ps 

module Pc #(parameter DataWidth =64;)(
  output     [DataWidth-1:0]   io_pc,
  input               clk,
  input               rst//现在还不能实现跳转,只能让pc自己累加
);
  reg        [DataWidth-1:0]   pc_reg;

  assign io_pc = pc_reg;
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      pc_reg <= 64'h80000000;
    end else begin
      pc_reg <= (pc_reg + 64'h80000000);
    end
  end
endmodule
