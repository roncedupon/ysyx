//50Mhz~2000ps
/*
200000~0.5Mhz

*/
module top#(parameter TIME=32'd1000_000_0)(
  input  clk,//输入时钟周期是50Mhz,分出来的时钟是:1/50Mhz*50_000=10000ps
  output en_o,
  input rst,
  output reg [7:0] out_q,   //输出计数器,没啥用了
  output reg [6:0]SEG_low,  //个位
  output reg [6:0]SEG_high  //十位
  );
  reg en;
  reg [31:0]counter;
  reg [3:0]counter_seg;//0~8计数器
  always @ (posedge clk or posedge rst)
    if (rst)begin 
        out_q<=8'b0;
    end
    else if (en)   out_q <= out_q +1;
    else if(out_q+1'b1=='d98)out_q<=0;
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


reg en_seg_low;//进位使能
//这里数10拍,0~9
always @(posedge clk or posedge rst)begin 
    if(rst)begin 
        counter_seg<=0;
        en_seg_low<=0;
    end
    else if(en&&counter_seg+1'b1!='d9)begin 
        counter_seg<=counter_seg+1'b1;
    end
    else if(counter_seg+1'b1=='d9)begin
        en_seg_low<=1'b1;
        counter_seg<=0;
    end
    else begin 
        counter_seg<=counter_seg;
        en_seg_low<=1'b0;
    end
end
reg [3:0]counter_seg_high;

always @(posedge clk or posedge rst)begin 
    if(rst)begin 
        SEG_high<=0;
        counter_seg_high<=0;
    end
    else if(en_seg_low&&counter_seg_high+1'b1!='d9) begin 
        counter_seg_high<=counter_seg_high+1'b1;
    end
    else if(counter_seg_high+1'b1=='d9)begin 
        counter_seg_high<=0;
    end
    else counter_seg_high<=counter_seg_high;
end
always @(posedge clk or posedge rst)begin
    if (rst)begin 
        SEG_high<=0;
    end 
    else
    case(counter_seg_high)
        4'b1001: SEG_high<=7'b0010000;
        4'b1000: SEG_high<=7'b0000000;
		4'b0111: SEG_high<=7'b1111000;
		4'b0110: SEG_high<=7'b0000010;
		4'b0101: SEG_high<=7'b0010010;
		4'b0100: SEG_high<=7'b0001010;
		4'b0011: SEG_high<=7'b0011001;
		4'b0010: SEG_high<=7'b0100100;
		4'b0001: SEG_high<=7'b1111001;
		4'b0000: SEG_high<=7'b1000000;
		default:SEG_high<=7'b1000000;
		endcase
end
always @(posedge clk or posedge rst)begin
    if (rst)begin 
        SEG_low<=0;
    end 
    else
    case(counter_seg)
        4'b1001: SEG_low<=7'b0010000;
        4'b1000: SEG_low<=7'b0000000;
		4'b0111: SEG_low<=7'b1111000;
		4'b0110: SEG_low<=7'b0000010;
		4'b0101: SEG_low<=7'b0010010;
		4'b0100: SEG_low<=7'b0011001;
		4'b0011: SEG_low<=7'b0110000;
		4'b0010: SEG_low<=7'b0100100;
		4'b0001: SEG_low<=7'b1111001;
		4'b0000: SEG_low<=7'b1000000;
		default:SEG_low<=7'b1000000;
		endcase
end
endmodule
