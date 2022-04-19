//译码单元:实现取指和译码之间的寄存器
//将取指阶段的结果在下一个时钟传给译码模块
module IF_ID(
	input clk,
	input rst,
	input [31:0]Inst,
	output[6:0]opcode,
	output[4:0]rd,
	output[2:0]fun,
	output[63:0]src1_o,
	output[63:0]src2_o,

	output[4:0]rs1,//寄存器一地址
	output[4:0]rs2,//寄存器二地址
	input reg[63:0]src1_i,
	input reg[63:0]src2_i,

	output[11:0]Imm
);
assign opcode=Inst[6:0];
assign rd=Inst[11:7];
assign fun=Inst[14:12];
assign rs1=Inst[19:15];
assign Imm=Inst[31:12];

assign src1_o=src1_i;
assign src2_o=src2_i;
endmodule