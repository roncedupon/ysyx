// Generator : SpinalHDL v1.6.1    git head : 3bf789d53b1b5a36974196e2d591342e15ddf28c
// Component : test1_area
// Git hash  : 526c5e5a99da6eb5a3f380252319cb0509217895

`timescale 1ns/1ps 

module test1_area (
  input               clk,
  input               reset
);

  reg        [7:0]    timer_counter;
  wire                timer_tick;

  assign timer_tick = (timer_counter == 8'h0);
  always @(posedge clk) begin
    timer_counter <= (timer_counter - 8'h01);
    if(timer_tick) begin
      timer_counter <= 8'h64;
    end
  end


endmodule
