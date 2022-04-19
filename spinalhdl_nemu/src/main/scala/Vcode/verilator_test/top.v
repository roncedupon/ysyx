//译码单元:实现取指和译码之间的寄存器
//将取指阶段的结果在下一个时钟传给译码模块
/* verilator lint_off WIDTH */
module top(
	input clk,
	input reg[31:0]Inst,//拿到的32位指令
	output[6:0]opcode,
	output[4:0]rd,
	output[2:0]fun,
	output[4:0]rs1,
	output[11:0]Imm,
	input rst
);
reg [6:0]		opcode_reg;
reg [4:0]		rd_reg;
reg [2:0]		fun_reg;
reg [4:0]		rs1_reg;
reg [11:0]		Imm_reg;
always@(posedge clk)begin
	if(rst)begin
		opcode_reg<=0;
		rd_reg<=0;
		fun_reg<=0;
		rs1_reg<=0;
		Imm_reg<=0;
	end
	else begin 
		opcode_reg<=Inst[6:0];
		rd_reg<=Inst[11:7];
		fun_reg<=Inst[14:12];
		rs1_reg<=Inst[19:15];
		Imm_reg<=Inst[31:12];
	end
end


assign opcode=opcode_reg;
assign rd=rd_reg;
assign fun=fun_reg;
assign rs1=rs1_reg;
assign Imm=Imm_reg;
endmodule