`timescale 1ns/1ps
//译码单元:实现取指和译码之间的寄存器
//将取指阶段的结果在下一个时钟传给译码模块
/* verilator lint_off WIDTH */
module IDU(
	//input 			clk,
	//input 			rst,
	input [31:0]	Inst,//拿到的32位指令
	output [6:0]	opcode,
	output wire[4:0]rd,
	output [2:0]	func3,//func3
	output [2:0]	func7,
	output [4:0]	rs1,
	output [4:0]	rs2,
	output [63:0]Imm,
	input [63:0]	src1_i,//从rs1寄存器里拿到的数据
	output [63:0]src1_o
 );
 assign src1_o=src1_i;
// assign rd=Inst[11:7];
// always@(posedge clk)begin
// 	if(rst)begin
// 		opcode<=0;
// 		//rd<=0;
// 		fun<=0;
// 		rs1<=0;
// 		Imm<=0;
// 		src1_o<=0;
// 	end
// 	else begin 
// 		opcode<=Inst[6:0];
// 		fun<=Inst[14:12];
// 		rs1<=Inst[19:15];
// 		Imm<={{52{Inst[31:31]}},Inst[31:20]};
// 		src1_o<=src1_i;
// 	end
// end
	wire I_type;
	wire U_type;
	wire J_type;
	wire B_type;
	wire S_type;
	
	wire [31:0]I_imme;
	wire [31:0]U_imme;
	wire [31:0]J_imme;
	wire [31:0]B_imme;
	wire [31:0]S_imme;
	
	
	assign opcode=Inst[6:0];
	assign func3=Inst[14:12];
	assign func7=Inst[30];
	assign rs1=Inst[19:15];
	assign rs2=Inst[24:20];
	assign rd =Inst[11:7];
	
	assign I_type=1;//(Inst[6:0]==`jalr) | (Inst[6:0]==`load) | (Inst[6:0]==`I_type);
	assign U_type=0;//(Inst[6:0]==`lui) | (Inst[6:0]==`auipc);
	assign J_type=0;//(Inst[6:0]==`jal);
	assign B_type=0;//(Inst[6:0]==`B_type);
	assign S_type=0;//(Inst[6:0]==`store);
	
	
	assign I_imme={{20{Inst[31]}},Inst[31:20]}; //立即数符号位扩展
	assign U_imme={Inst[31:12],{12{1'b0}}};
	assign J_imme={{12{Inst[31]}},Inst[19:12],Inst[20],Inst[30:21],1'b0};   
	assign B_imme={{20{Inst[31]}},Inst[7],Inst[30:25],Inst[11:8],1'b0};
	assign S_imme={{20{Inst[31]}},Inst[31:25],Inst[11:7]}; 
	
	assign Imm= I_type?I_imme :
				U_type?U_imme :
				J_type?J_imme :
				B_type?B_imme :
				S_type?S_imme : 32'd0;

	//产生寄存器读写信号
endmodule





