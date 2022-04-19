`timescale 1ns/1ps
module EXU(
	input 			clk,
	input 			rst,
	input wire[4:0]	rd_i,
	input wire[63:0]src1,
	input wire[63:0]Imm,
	output reg[4:0]	rd_o,
	output reg[63:0]result
);
//仅处理addi
always @(posedge clk)begin
	if(rst)begin
		rd_o<=0;
		result<=0;
	end
	else begin
		result<=Imm+src1;
		rd_o<=rd_i;
	end
end
endmodule