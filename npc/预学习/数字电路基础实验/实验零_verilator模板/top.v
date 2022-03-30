// module top(
//     input clk,
//     input rst,
//     output [6:0]digital
// );
// reg [31:0]counter;//计数器
// reg en;
// reg [6:0]digital;
// always @(posedge clk or posedge rst)begin
//     if(rst)begin//高复位
//         digital<=0;
//         counter<=0;
//         en<=0;
//     end
//     else begin
//         if(counter<31'd50_000_000_0)
//             counter<=counter+1'b1;
//         else
//             en<=1;
//     end
// end
// always @(posedge clk)begin
//     if(en)begin
//         digital<=digital+1'b1;
//     end
//     else begin 
//         digital<=digital;
//     end
//50Mhz~2000ps
/*
200000~0.5Mhz

*/
// end

// endmodule
module top#(parameter TIME=32'd500_000_000)(clk,out_q,rst,en_o);
  input  clk;//输入时钟周期是50Mhz,分出来的时钟是:1/50Mhz*50_000=10000ps

  output en_o;
  input rst;
  output reg [7:0] out_q;
  reg en;
  reg [31:0]counter;
  always @ (posedge clk or posedge rst)
    if (rst)begin 
        out_q<=8'b0;
    end
    else if (en)   out_q <= out_q +1;
    else if(out_q+1'b1=='d99)out_q<=0;
    else out_q<=out_q;

always @(posedge clk or posedge rst)begin 
    if(rst)begin 
        counter<=0;
    end
    else if(counter<TIME)counter<=counter+1'b1;
    else counter<=0;
end
always @(posedge clk or posedge rst)begin 
    if(rst)begin 
        en<=0;
    end
    else if(counter+1'b1==TIME) en<=1'b1;
    else en<=0;
end
assign en_o=en;

endmodule
