module RegisterFile #(ADDR_WIDTH = 5, DATA_WIDTH = 64) (
  input clk,
  input [DATA_WIDTH-1:0] wdata,//写数据
  input [ADDR_WIDTH-1:0] waddr,//写地址
  input rst,
  input wen,
  input ren,//读使能
  input raddr,//读地址
  output  reg[DATA_WIDTH-1:0]rdata
);
  reg [DATA_WIDTH-1:0] rf [ADDR_WIDTH-1:0];
  always @(posedge clk) begin
    if (wen) rf[waddr] <= wdata;
  end
  always @(posedge clk) begin
    if (ren)  rdata<= rf[raddr];
  end
  always @(posedge clk or posedge rst) begin
    rdata<=0;//复位就全部清零
  end
endmodule
