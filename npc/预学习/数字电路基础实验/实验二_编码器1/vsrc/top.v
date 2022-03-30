module top(
	input [7:0]in,
	input en,//enable signal,
	output  en_led,
	output reg[2:0] out,
	output reg [6:0]SEG
);
	always@(in or en)begin
	if(en==1'b1)begin
		casez (in)
		8'b1???????: out<=3'b111;
		8'b01??????: out<=3'b110;
		8'b001?????: out<=3'b101;
		8'b0001????: out<=3'b100;
		8'b00001???: out<=3'b011;
		8'b000001??: out<=3'b010;
		8'b0000001?: out<=3'b001;
		8'b00000001: out<=3'b000;
		default: out=3'b000;
		endcase
		case(out)
		3'b111: SEG<=7'b1111000;
		3'b110: SEG<=7'b0000010;
		3'b101: SEG<=7'b0001010;
		3'b100: SEG<=7'b0001101;
		3'b011: SEG<=7'b0110000;
		3'b010: SEG<=7'b0100100;
		3'b001: SEG<=7'b1111001;
		3'b000: SEG<=7'b1111000;
		default:SEG<=7'b0;
		endcase
		
	end
		
		
		
		
		
	end
	assign en_led=en;

endmodule
