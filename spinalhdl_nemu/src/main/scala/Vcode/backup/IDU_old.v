module IDU(//解码单元
	input clk,
	input rst,
	input reg[31:0]Inst,//拿到指令
	input reg [63:0]src1,//
	output reg inst_out,
	output [4:0]rd,//向寄存器能写入数据
	output [4:0]rs1,
	output [63:0]Imm,//12位立即数
	output [5:0]Instype
);
always@(posedge clk)begin
	if(rst)inst_out<=0;
	else begin
		casez (Inst)
		32'b????????????_?????_000_?????_0010011:begin//00000000000000000000000000010011
			inst_out<=1'b1;
			rd<=Inst[11:7];
			rs1<=Inst[19:15];
			Imm<={52{Inst[31:31]},Inst[31:20]};	//立即数符号位扩展
			Instype<=6'b000001;//独热码表示指令类型
		end
		default: inst_out<=0;
		endcase
	end
end



endmodule