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

    top->clk    = 0;
    top->rst_n  = 0;

    top->trace(tfp, 0);
    tfp->open("wave.vcd");

    while (sc_time_stamp() < 1000 && !Verilated::gotFinish()) {
        if (main_time > 14) {
            top->rst_n = 1;
        }
        if ((main_time % 10) == 5) {
            top->clk = 1;
        }
        if ((main_time % 10) == 0) {
            top->clk = 0;
        }

        top->eval();
        tfp->dump(main_time);
        main_time++;
    }

    top->final();
    tfp->close();
    delete top;

    return 0;
}