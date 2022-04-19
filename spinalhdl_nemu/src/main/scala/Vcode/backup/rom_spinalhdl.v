// Generator : SpinalHDL v1.6.1    git head : 3bf789d53b1b5a36974196e2d591342e15ddf28c
// Component : rom_spinalhdl
// Git hash  : 0525e73eb5472b586b775db09c699e2bed04aa81
`timescale 1ns/1ps 
//从rom中拿到指令,取指
module rom_spinalhdl (
  input               writeValid,
  input      [4:0]    writeAddress,
  input      [63:0]   writeData,

  input               readValid_1,
  input      [4:0]    readAddress_1,
  output     [63:0]   readData_1,

  input               readValid_2,
  input      [4:0]    readAddress_2,
  output     [63:0]   readData_2,
  input               clk
  //input               reset
);
  reg        [31:0]   _zz_mem_port1;
  reg [31:0] mem [0:255];
  always @(posedge clk) begin
    if(writeValid) begin
      mem[writeAddress] <= writeData;
    end
  end

  always @(posedge clk) begin
    if(readValid) begin
      _zz_mem_port1 <= mem[readAddress];
    end
  end
  assign readData = _zz_mem_port1;




endmodule
