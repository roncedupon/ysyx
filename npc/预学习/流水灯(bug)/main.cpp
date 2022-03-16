#include "verilated_vcd_c.h"
#include "Vtop.h"
vluint64_t main_time = 0;
double sc_time_stamp()
{
    return main_time;
}

void single_cycle(Vtop*top) {
  top->clk = 0; top->eval();
  top->clk = 1; top->eval();
}

void reset(int n,Vtop*top) {//复位几个周期
  top->rst = 1;
  while (n -- > 0) single_cycle(top);
  top->rst = 0;
}



int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    Vtop *top = new Vtop("top");
    top->trace(tfp, 0);
    tfp->open("wave.vcd");
    
    
    reset(10,top);  // 复位10个周期
    
    
    while (sc_time_stamp() < 10000 && !Verilated::gotFinish()) {
	        single_cycle(top);
	        
        tfp->dump(main_time);
        main_time++;
    }
    top->final();
    tfp->close();
    delete top;
    return 0;
}

