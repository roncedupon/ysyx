#include "verilated_vcd_c.h"
#include "Vtop.h"
//#include <nvboard.h>
//top的信号
/*
input clk,
input rst,
output reg [15:0] led
*/
//double sc_time_stamp() { return 0; }//这玩意不知道是干啥的,没啥用
int main(int argc, char** argv, char** env) {
    // nvboard_bind_all_pins(&dut);
    // nvboard_init();


// Prevent unused variable warnings
    if (false && argc && argv && env) {}//这也没啥用
    //verilator配置开始
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
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
 
    while (!contextp->gotFinish()&&contextp->time()<10000000) {
        if((contextp->time())%1000==1)top->clk = !top->clk;//1000ps复位
       contextp->timeInc(1);//1ps
       
       if (!top->clk) {
            if (contextp->time() > 1 && contextp->time() < 10) {
                top->rst = !0;  // 复位10单位
            } else {
                top->rst = !1;  // Deassert reset
            }
            // 还是在if里面写其他的信号描述

        }
        top->eval();//verilator跑一把
        tfp->dump(contextp->time());//把波形信号写入
     }
    //nvboard_quit();
    top->final();//模板

    return 0;
}

