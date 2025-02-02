//TESTBENCH

#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream> 

int main(int argc, char **argv, char **env) {
    int i;
    //counts number of clock cycles to simulate
    int clk;
    //clk = clock signal

    Verilated::commandArgs(argc, argv);
   
    // init top verilog instance
    // instantiate the counter module - this is a DUT
    // DUT = Device Under Testing
    Vcounter* top = new Vcounter;
   
    // init trace dump
    // turn on signal tracing and
    // tell Verilator to dump waverform data to counter.vcd
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("counter.vcd");

    // initialize simulation inputs
    // top = top-level entity
    // only top-level signals are visible
    top->clk = 1;
    top->rst = 1;
    top->en = 0;

    // run simulation for many clock cycles
    for (i=0; i<300; i++) {
        top->en = 1;
        std::cout<<int(top->count)<<std::endl;
        //want to compare top->counter rather than picking i
        if (i==12 || i==13){
            top->en = 0;
            std::cout<<int(top->en)<<std::endl;
                //std::cout<<int(top->count)<<std::endl;    
            
        }
    /*top->en = 1;
        //want to compare top->counter rather than picking i
        if(int(top->count)==9){
            for(int j; j<3;j++){
                top->en =0;
            }
        }*/
        
        // dump variables into VCD file and toggle clock
        for(clk=0; clk<2; clk++) {
            tfp->dump (2*i+clk);
            top->clk = !top->clk;
            top->eval ();
        }
//when counter = 0x9, enable switches off and clock held for 3 cycles

        top->rst = (i <2);
        //top->en = (i>4);

        if (Verilated::gotFinish()) exit(0);
    }

    tfp->close();
    exit(0);
}
