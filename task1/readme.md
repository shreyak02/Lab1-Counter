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

## Step 4: Create testbench counter_tb.cpp in C++

![image](https://user-images.githubusercontent.com/21007664/198900326-1f080f59-5fde-4cea-b6e4-edae6b755b4b.png)

## Step 5: Compile the System Verilog model with the testbench
 
* Create a shell script to run the Verilator to translate counter.sv into C++ code, and merge with counter_tb.cpp to produce executable files. Vcounter.mk is the file that will be generated to produce the final simulation Vcounter. Vcounter.vcd is a file that can be run on GTKwave to produce a trace waveform file and contain the simulation results.
 
 ## Step 6: Plot the counter waveforms with GTKwave:
 
 ![image](https://user-images.githubusercontent.com/21007664/199223250-c168da38-922b-4063-b0a4-f4a5bd439a00.png)

* As seen in the testbench code, the reset signal is on when the clock is less than 2 cycles or equal to the positive edge of the 15th clock cycle.
when reset is on the counter goes to 0 on the next clock cycle.
* Enable remains on after the 4th clock cycle. The counter only counts when enable is high.
* Axis is in ps to represent the period for the clock cycle, it doesn't matter what scale is used.

## Challenge 1:

Modify the testbench so that you stop counting for 3 cycles once the counter reaches 0x9, and then resume counting. You may also need to change the stimulus for rst.

![image](https://user-images.githubusercontent.com/21007664/199230062-e982a3c6-b382-4dd0-90e4-51e18e4ba227.png)
![image](https://user-images.githubusercontent.com/21007664/199670082-212fb51a-33b1-4a42-beb5-0e9e90fb49ae.png)

* Due to the one cycle delay, begin by storing the value of the index i, when the counter reaches 8 (to work for any case rather than hardcoding the value i in). 
* For the counter to stop when the count is 9, enable is set to 0 for the i+1 and i+2 clock cycles. Due to the one cycle delay the counter stays off for another cycle meaning we don't have to set enable to 0 for a third cycle.
* Attempted to directly compare the value when count = 9 and set enable to 0, however due to the posedge clk changes can only happen each clock cycle.

Q) WHY DOES THE IF HAVE TO BE STORE + 1 AND +2 RATHER THAN (STORE AND THEN STORE +1 and set count to 9)? BCOS IF WE DO THIS WE GET AN INFINITE LOOP.

## Challenge 2:

The current counter has a synchronous reset. To implement asynchronous reset, you can change line 11 of counter.sv to detect change in rst signal. 

**Before:**

![image](https://user-images.githubusercontent.com/21007664/199233358-196310f9-e846-4413-a3ae-530f118d2d0a.png)

![image](https://user-images.githubusercontent.com/21007664/199233306-bce1f7e5-66c2-42a4-86e7-59bd7ada16ee.png)

* Synchronus means that reset happens only on the active edge of the clock signal.

**After:**

![image](https://user-images.githubusercontent.com/21007664/199233135-44b2946d-2381-4da1-9b32-75823a6f7eee.png)

![image](https://user-images.githubusercontent.com/21007664/199233022-11376e12-1575-41d4-9bcb-465a0f5ad742.png)

* An asynchronus reset can happen anytime whenever the reset signal is asserted and is independent of the clock. Posedge reset is sensitive to rising edge of reset.
