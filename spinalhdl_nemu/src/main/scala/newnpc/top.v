`timescale 1ns/1ps
module top(
	input clk,
	input rst,
	input wire [31:0]Inst,
	output wire en,
	output wire [31:0]pc_addr
);
pc_reg pc_reg(
	.clk(clk),
	.rst(rst),
	.pc(pc_addr),
	.en(en)
);

IDU IDU(
	//.clk(clk),
	//.rst(rst),
	.Inst(Inst),
	/* verilator lint_off PINCONNECTEMPTY */.opcode(),/* verilator lint_off PINCONNECTEMPTY */
	.rd(rd_IDU),
	/* verilator lint_off PINCONNECTEMPTY */.func3(),/* verilator lint_off PINCONNECTEMPTY */
	/* verilator lint_off PINCONNECTEMPTY */.func7(),/* verilator lint_off PINCONNECTEMPTY */
	.rs1(rs1),
	/* verilator lint_off PINCONNECTEMPTY */.rs2(),/* verilator lint_off PINCONNECTEMPTY */
	.Imm(Imm),
	.src1_i(src1_i),
	.src1_o(src1_o)
);
wire [4:0]rs1;
wire [63:0]src1_i;
wire [63:0]src1_o;
wire [63:0]Imm;
wire [4:0]rd_IDU;
wire [4:0]rd_EXU;
wire [63:0]result;
EXU EXU(
	.clk(clk),
	.rst(rst),
	.src1(src1_o),
	.Imm(Imm),
	.rd_i(rd_IDU),
	.rd_o(rd_EXU),
	.result(result)
);
register_file register_file(
	.clk(clk),
	.rst(rst),
	.writeValid(1),
	.writeAddress(rd_EXU),
	.writeData(result),
	// .readValid_2(0),
	// .readAddress_2(0),
	// .readData_2(read_nothing),
	.readValid_1(1),
	.readAddress_1(rs1),
	.readData_1(src1_i)
);

endmodule