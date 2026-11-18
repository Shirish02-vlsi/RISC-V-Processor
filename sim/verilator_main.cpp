// ============================================================================
// verilator_main.cpp - Verilator Main Entry Point
// ============================================================================

#include "Vrv32i_verilator_tb.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "verilated_cov.h"

vluint64_t main_time = 0;

double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    // Enable VCD tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    
    Vrv32i_verilator_tb* top = new Vrv32i_verilator_tb;
    top->trace(tfp, 99);
    tfp->open("sim/waveform.vcd");
    
    // Run simulation
    while (!Verilated::gotFinish()) {
        top->eval();
        tfp->dump(main_time);
        main_time += 5; // 5ns half-period
    }
    
    // Final coverage
    system("mkdir -p logs");
    system("mkdir -p ../sim/logs");
    
    VerilatedCov::write("logs/coverage.dat");
    printf("VerilatedCov::write called for logs/coverage.dat\n");
    
    VerilatedCov::write("../sim/logs/coverage.dat");
    printf("VerilatedCov::write called for ../sim/logs/coverage.dat\n");
    
    top->final();
    tfp->close();
    delete top;
    delete tfp;
    
    return 0;
}