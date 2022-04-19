`timescale 1ns/1ps
module pc_reg(
	input wire 		clk,
	input wire 		rst,
	output reg[31:0]	pc,
	output reg 		en//读指令使能
);
always@(posedge clk)begin
	if(rst)begin
		en<=0;//复位读使能拉低
	end
	else begin
		en<=1'b1;
	end
end
always @(posedge clk)begin
	if(rst)begin
		pc<=32'h80000000;
	end
	else begin
		pc<=pc+32'h1;//pc每次加1
	end
end
endmodule