#include "verilated_vcd_c.h"
#include "Vtop.h"

vluint64_t main_time = 0;

double sc_time_stamp()
{
    return main_time;
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    Vtop *top = new Vtop("top");
    top->trace(tfp, 0);
    tfp->open("wave.vcd");

    while (sc_time_stamp() < 10000 && !Verilated::gotFinish()) {
        int a = rand() & 1;
        int b = rand() & 1;
        top->a = a;
        top->b = b;
        top->eval();
        tfp->dump(main_time);
        main_time++;
    }

    top->final();
    tfp->close();
    delete top;
    return 0;
}