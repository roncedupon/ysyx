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

genvar i;
generate
  for(i=0;i<32;i=i+1)begin:fuck
    always@(posedge clk)
      if(rst)
        mem[i]<=0;
  end
endgenerate


  reg        [63:0]   _zz_mem_port1;
  reg [63:0] mem [0:31];

  always @(posedge clk) begin
    if(rst)begin
      // mem[31]<=0;
      // mem[30]<=0;
      // mem[29]<=0;
      // mem[28]<=0;
      // mem[27]<=0;
      // mem[26]<=0;
      // mem[25]<=0;
      // mem[24]<=0;
      // mem[23]<=0;
      // mem[22]<=0;
      // mem[21]<=0;
      // mem[20]<=0;
      // mem[19]<=0;
      // mem[18]<=0;
      // mem[17]<=0;
      // mem[16]<=0;
      // mem[15]<=0;
      // mem[14]<=0;
      // mem[13]<=0;
      // mem[12]<=0;
      // mem[11]<=0;
      // mem[10]<=0;
      // mem[9]<=0;
      // mem[8]<=0;
      // mem[7]<=0;
      // mem[6]<=0;
      // mem[5]<=0;
      // mem[4]<=0;
      // mem[3]<=0;
      // mem[2]<=0;
      // mem[1]<=0;
      // mem[0]<=0;  
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
