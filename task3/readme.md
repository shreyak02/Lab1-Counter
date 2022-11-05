# Task 3 - Vbuddy parameter & flag in one-shot mode

* The rotary encoder (EC11) provides input from Vbuddy to the Verilator simulation model.
* Turning the encoder changes a stored parameter value on Vbuddy independently from the Verilator simulation.
* **vbdValue():** reads parameter value from the Vbuddy rotary encoder.
* **vbdFlag():** Returns current value of flag -- assumes 0 if not specified by setMode()
* **vbdSetMode()** 0 = toggle, 1 = one shot (armed)
* One shot behaviour means whenever flag is pressed, the flag register is set to '1' and the flag is 'ARMED' ready to fire. However, once the flag register is read it immediately resets to 0 (like an impulse function).
0 mode means flag is held in that state until switch is pressed again.

## Modify counter.sv to increment counter each time switch is pressed.

* Create a folder with counter.sv, counter_tb.cpp, vbuddy.cpp, doit.sh, vbuddy.cfg
* Modify counter.sv so pressing the switch on EC11 forces the counter to pre-set Vbuddy's parameter value. Use the one-shot behaviour of the Vbuddy flag to provide one clock pulse each time the rotary encoder is pressed for single step counting action.
