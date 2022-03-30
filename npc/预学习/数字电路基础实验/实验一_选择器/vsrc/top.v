module top(
     input [1:0]x0,
     input [1:0]x1,
     input [1:0]x2,
     input [1:0]x3,
     input [1:0]s,
     output reg [1:0]y
     
);
always@(*)begin
          case(s)
               2'b00 : y=x0;
               2'b01 : y=x1;
               2'b10 : y=x2;
               2'b11 : y=x3;
               default : y=2'b11;
          endcase
     end
endmodule
