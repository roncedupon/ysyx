#include "verilated_vcd_c.h"
#include "Vtop.h"
#include <verilated.h>
#include <memory>
//#include <nvboard.h>
//top的信号
/*
input clk,
input rst,
output reg [15:0] led
*/
//double sc_time_stamp() { return 0; }//这玩意不知道是干啥的,没啥用
int SWITCH=0;//选择要不要输出波形,0不要,1要
int main(int argc, char** argv, char** env) {
    // nvboard_bind_all_pins(&dut);
    // nvboard_init();


// Prevent unused variable warnings
    //if (false && argc && argv && env) {}//这也没啥用
    //verilator配置开始
    Verilated* contextp = NULL;
    contextp->debug(0);// Set debug level, 0 is off, 9 is highest presently used
    contextp->randReset(2);// Randomization reset policy
    contextp->traceEverOn(true);// Verilator must compute traced signals--开启波形
    contextp->commandArgs(argc, argv); // Pass arguments so Verilated code can see them, e.g. $value$plusargs
                                      // This needs to be called before you create any model
    //verilator配置结束

    Vtop *top = new Vtop("top");
    
    //初始化时钟和复位信号
    top->rst=!0;
    top->clk=0;
    //生成波形
    VerilatedVcdC* tfp = new VerilatedVcdC;//模板
    top->trace(tfp, 0);//模板
    tfp->open("wave.vcd");//模板
    //模拟50Mh时钟
    const long int Total_Time=1000000;//总时间1ms,
	int main_time=0;
    while (!contextp->gotFinish()&&main_time<Total_Time*5) {
        main_time++;//1ps
        if((main_time)%1000==1)top->clk = !top->clk;//2000ps一个周期--50Mhz
       if (!top->clk) {
            if (main_time > 1 && main_time < 10) {
                top->rst = !0;  // 复位10单位
            } else {
                top->rst = !1;  // Deassert reset
            }
            // 还是在if里面写其他的信号描述
            //printf("%x\n",top->out_q);
        }
        // if(top->en_o){错误写法
        //     printf("fuck");
            // top->eval();//verilator跑一把
            // tfp->dump(main_time);//把波形信号写入
        // }
        top->eval();//verilator跑一把
        tfp->dump(main_time);//把波形信号写入
     }
    //nvboard_quit();
    top->final();//模板

    return 0;
}

