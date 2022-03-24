module top(
    input [2:0]function_chosing,
    output out_led,//led指示灯,
    input [3:0]signed_A,
    input [3:0]signed_B,
    input clk,
    input rst,
    //输入有符号数的补码
    //正数的补码就是源码本身
    //负数的补码是反码加一
    //-2->1010(源码)--1101(反码,除符号位以外都取反)--1110(补码)
    //1->0001
    //-2+1=-1----1110+0001=1111(计算结果的补码,转为源码)先减一
                    //1111-0001=1110
                    //除符号位以外都取反:1001

                    

    output reg[4:0]out_result//计算结果
);
always@(posedge clk or posedge rst) begin
        
        case(function_chosing)
            3'b000:begin
                out_result<=signed_A+signed_B;
                if(out_result[3])begin//如果输出结果是负数,将负数补码转为源码
                    out_result<=out_result-1;
                    out_result<={out_result[3],~out_result[2:0]};
                end
            end           //A+B






            3'b001:begin
                out_result<=signed_A-signed_B;
            end  //A-B
            3'b010:out_result<=~signed_A; //Not A取反
            3'b011:out_result<=signed_A&signed_B;           //A and B与
            3'b100:out_result<=signed_A|signed_B;//A or B 或
            3'b101:out_result<=signed_A^signed_B;//A xor B 异或
            3'b110:A<B?out<=1'b1:out<=1'b0;           //比较大小:A<B?out=1:out=0
            3'b111:A==B?out<=1'b1:out=1'b0;           //判断相等:A==B?out=1:out=0
        endcase
    end
endmodule