# Task4- Displaying count as Binary Coded Decimal (BCD) numbers

* So far only implemented single modules, objective is to create a top-level module (top.sv) which has the counter moduke,
 and a second module that converts the 8 bit binary number into 3 BCD digits.
* Modification to previous counter, where 7-segment display will diplay BCD rather than hex digits (BCD is easier for humans to understand when counting).

## Shift and add 3 algorithm

* This is the alogrithm that converts binary numbers into BCD digits.
* Binary number is shifted left one bit at a time into a temporary register 'result'
* If bottom 4 bits of results >=5 then add 3 (only once) - this is because if the value >=5, then the next shift will produce a 4 bit value to large to be represented by one BCD character.
* Continue shifting x into result until all bits in the binary number have been processed.

**bin2bcd.sv**

Single module that converts binary input from counter to BCD using the shift add 3 algorithm.

![image](https://user-images.githubusercontent.com/21007664/200191847-31912a56-7529-4f28-aa6a-dda6768f5734.png)


**counter.sv**

Single module that simply behaves as a counter when reset is not high. Specified in previous tasks.

![image](https://user-images.githubusercontent.com/21007664/200191985-22359b51-ef7a-4a7f-8d5f-0462a4c444bc.png)

**top.sv**
![image](https://user-images.githubusercontent.com/21007664/200192451-2dc10552-49a5-454d-9c2a-56fc48c0124f.png)

![image](https://user-images.githubusercontent.com/21007664/200192457-92e84086-3309-40ca-bc85-9b9d052d6ca7.png)

* This is a top level sheet which provides an overall view and connects modules together.
* All inputs and outputs to the system must be defined with a logic wire.
* The logic wire count, is an interconnecting wire that connects the counter block to the bin2bcd block.
* .count (count) --> value in bracket gets passed along the count interconnect wire into .x which is the input to the bin2bcd block
* .BCD(bcd) sends output value to the output wire.

**doit.sh**

![image](https://user-images.githubusercontent.com/21007664/200192534-e3212a08-1b7c-402d-b767-37067bee8bab.png)

* Script modified to merge the testbench with the top level sheet to produce a verilated vcd file for simulation.

**Result:**

![image](https://user-images.githubusercontent.com/21007664/200192674-02a99632-eb88-409a-9931-e39be5f33793.png)

* BCD value 10 dispalyed as opposed to hex A as shown previously.


