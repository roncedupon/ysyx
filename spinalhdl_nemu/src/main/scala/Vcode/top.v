module top(
	input clk,
	input rst,
	output reg[63:0] pc_addr,//将pc地址暴露出去,从外面的c语言数组拿指令
	input wire[31:0] Inst,
);
wire[63:0] PC_wire;
assign pc_addr=PC_wire;



Pc PC_module#(.DataWidth(64))(
	.io_pc(PC_wire),//out
	.clk(clk),
	.rst(rst)	
);




// IF_ID IF_ID(
// .clk(clk),
// .rst(rst),
// .Inst(Inst),
// .opcode(),//out
// .rd(),
// .fun(),
// .rs1(),
// .Imm()

// );




register_file registers(

);




endmodule