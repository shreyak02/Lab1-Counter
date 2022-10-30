# Lab 1- Learning System Verilog with Verilator and VBuddy

* **System Verilog:** a hardware description and verification language (HDL) mostly for designing digital hardware.

* **Verilator:** A software package to simulate SV. Circuit states only evaluated once in a clock cycle. It doesn't evaluate time within a clock cycle, therefore only suitable for functional verification without timing information. Most modern digital circuits are synchronus therefore, executed fast with verilator.
  * Translates SV into C++ code. Then uses a C++ compiler to produce an executable program of the design (device-under-testing DUT). Simulation happens when you run this program.

* **Verilator Testbench:** A disadvantage of translating a Verilog design in C++ executable is we cannot interact with the simulator. To know if the DUT is working, have to write a "wrapper" program that instantiates the DUT, provide input signals and display output signals. The wrapper program is known as a testbench for the DUT.

* **Vbuddy:** A bridge between the verilator simulator and actual physical electronics (microphone, 7 segment display). Using verilator normally is like software development...no way of interacting with the DUT. 

## Task 1 - Simulating a basic 8-bit binary counter

### Set Up:
* Fork the github repository to my github account and clone a copy to my local disk. 
* Create a System Verilog file (counter.sv):
![image](https://user-images.githubusercontent.com/21007664/198896747-a05a8b70-30da-419c-8c2e-47570b3233bd.png)
* File name and the module name must be the same.
* Number of bits in the counter is specified with the parameter WIDTH. (Currently set to 8 bit)
* The always_ff @(posedge clk) is the way to specify a clocked circuit.
** <= are non-block assignments that are always used within an always_ff block.
** { , } is a concatenation operator to form 8 bits of 0.
** WIDTH-1 creates 7 bits of '0' and if enable=1 then LSB becomes 1 (concatenates count with enable).

![image](https://user-images.githubusercontent.com/21007664/198899941-07b366df-e9ca-42ca-bcfd-e98923c0992c.png)

