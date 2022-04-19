`timescale 1ns/1ps
module IF_ID(//寄存器
	input wire 			clk,
	input wire 			rst,
	input wire[63:0]	pc_reg_i,
	input wire[31:0]	Inst_i,//32位指令
	output reg[63:0]	pc_reg_o,
	output reg[31:0]	Inst_o,
);
always@(posedge clk)begin
	if(rst)begin
		pc_reg_o<=0;
		Inst_o<=0;
	end
	else begin
		pc_reg_o<=pc_reg_i;
		Inst_o<=Inst_i;
	end
end
endmodule