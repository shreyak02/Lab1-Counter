# Task 3 - Vbuddy parameter & flag in one-shot mode

* The rotary encoder (EC11) provides input from Vbuddy to the Verilator simulation model.
* Turning the encoder changes a stored parameter value on Vbuddy independently from the Verilator simulation.
* **vbdValue():** reads parameter value from the Vbuddy rotary encoder.
* **vbdFlag():** Returns current value of flag -- assumes 0 if not specified by setMode()
* **vbdSetMode()** 0 = toggle, 1 = one shot (armed)
  *Vbuddy's flag register has two modes of operation.
* One shot behaviour means whenever flag is pressed, the flag register is set to '1' and the flag is 'ARMED' ready to fire. However, once the flag register is read it immediately resets to 0 (like an impulse function).
0 mode means flag is held in that state until switch is pressed again.

## Modify counter.sv to increment counter each time switch is pressed.

* Create a folder with counter.sv, counter_tb.cpp, vbuddy.cpp, doit.sh, vbuddy.cfg
* Modify counter.sv so pressing the switch on EC11 forces the counter to pre-set Vbuddy's parameter value. Use the one-shot behaviour of the Vbuddy flag to provide one clock pulse each time the rotary encoder is pressed for single step counting action.

**counter_tb.cpp**

![image](https://user-images.githubusercontent.com/21007664/200191217-27b84dc4-e12d-48bc-9e28-de0e5dc8a31d.png)

* **vbdSetMode(1)** sets the flag to one-shot behaviour, therefore flag is 1 until it is read. 
* **top->incr** is set by vbdFlag() whose value only goes high when the switch is pressed as the device is in one-shot mode.

**counter.sv**

![image](https://user-images.githubusercontent.com/21007664/200191335-6b6fbaa8-961f-4b9e-9029-472b03467355.png)

* If reset is high then display 8 bits of 0. (Not the case as reset set to 0 in testbench).
* If both reset and enable are low counter counts down, as designed in previous task. (Not the case as enable is set to 1 in testbench).
* If incr is high, (incr value decided by vbdFlag which only goes high when switch is pressed as designed in the testbench), only then the counter will count up.
