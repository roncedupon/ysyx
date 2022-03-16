#include "verilated_vcd_c.h"
#include "Vtop.h"
//top的信号
/*
input clk,
input rst,
output reg [15:0] led
*/
double sc_time_stamp() { return 0; }
int main(int argc, char** argv, char** env) {
    
// Prevent unused variable warnings
    if (false && argc && argv && env) {}
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
    contextp->debug(0);// Set debug level, 0 is off, 9 is highest presently used
    contextp->randReset(2);// Randomization reset policy
    contextp->traceEverOn(true);// Verilator must compute traced signals
    contextp->commandArgs(argc, argv); // Pass arguments so Verilated code can see them, e.g. $value$plusargs
                                      // This needs to be called before you create any model
    Vtop *top = new Vtop("top");
    
    //初始化信号
    top->rst=!0;
    top->clk=0;
    //生成波形
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 0);
    tfp->open("wave.vcd");

    while (!contextp->gotFinish()&&contextp->time()<10000) {
       contextp->timeInc(1);
       top->clk = !top->clk;
       if (!top->clk) {
            if (contextp->time() > 1 && contextp->time() < 10) {
                top->rst = !0;  // 前10秒复位
            } else {
                top->rst = !1;  // Deassert reset
            }
            // 还是在if里面写其他的信号描述

        }
        top->eval();
        tfp->dump(contextp->time());
        //printf("analyse\n");
        //printf("%d\n",top->led[1])
        // VL_PRINTF("clk=%x ,rstl=%x , owide=%x\n",
        //            top->clk, top->rst, top->led[0]);
     }
    top->final();

    return 0;
}

