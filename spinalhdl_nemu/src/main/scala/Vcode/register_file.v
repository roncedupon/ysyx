// Generator : SpinalHDL v1.6.1    git head : 3bf789d53b1b5a36974196e2d591342e15ddf28c
// Component : register_file
// Git hash  : 0525e73eb5472b586b775db09c699e2bed04aa81

`timescale 1ns/1ps 

module register_file (
  input               writeValid,
  input      [4:0]    writeAddress,
  input      [63:0]   writeData,
  input               readValid_1,
  input      [4:0]    readAddress_1,
  output     [63:0]   readData_1,
  input               clk,
  input               rst
);

  reg        [63:0]   _zz_mem_port1;
  reg [63:0] mem [0:31];

  always @(posedge clk) begin
    if(rst)begin
      mem[writeAddress] <= 0
    end
    else if(writeValid) begin
      mem[writeAddress] <= writeData;
    end
  end

  always @(posedge clk) begin
    if(rst)begin
     _zz_mem_port1 <=0;
    end
    else if(readValid_1) begin
      _zz_mem_port1 <= mem[readAddress_1];
    end
  end
  assign readData_1 = _zz_mem_port1;

endmodule
