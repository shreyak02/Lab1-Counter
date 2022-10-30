# Lab 1- Learning System Verilog with Verilator and VBuddy

* **System Verilog:** a hardware description and verification language (HDL) mostly for designing digital hardware.

* **Verilator:** A software package to simulate SV. Circuit states only evaluated once in a clock cycle. It doesn't evaluate time within a clock cycle, therefore only suitable for functional verification without timing information. Most modern digital circuits are synchronus therefore, executed fast with verilator.
  * Translates SV into C++ code. Then uses a C++ compiler to produce an executable program of the design (device-under-testing DUT). Simulation happens when you run this program.

* **Verilator Testbench:** A disadvantage of translating a Verilog design in C++ executable is we cannot interact with the simulator. To know if the DUT is working, have to write a "wrapper" program that instantiates the DUT, provide input signals and display output signals. The wrapper program is known as a testbench for the DUT.

* **Vbuddy:** A bridge between the verilator simulator and actual physical electronics (microphone, 7 segment display). Using verilator normally is like software development...no way of interacting with the DUT. 
