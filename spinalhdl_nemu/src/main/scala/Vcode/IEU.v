module IEU(
	input clk,
	input rst,
	input [5:0]Instype,//指令类型
	input reg[4:0]rd_in,//向寄存器内写
	input [63:0]rs1,//从rs1寄存器拿到的64bit数据
	input [63:0]rs2,//从rs2寄存器拿到的64bit数据
	input [63:0]Imm,
	output [63:0]result,
	output [4:0]rd_out
);
assign rd_out=rd_in;
always @(posedge clk )begin
	if(rst)begin
		result<=0;
	end
	else begin 
		result<=rs1+Imm;
	end
end
//读在读取阶段
//写在写回阶段
//x[rd]=x[rc1]+sext(imm)


end



endmodule