## Task 2: Linking Verilator simulation with Vbuddy

### Step 1: Set up the Vbuddy interface

* Objective is to learn how to modify the testbench to interface with the Vbuddy board.
* Copy counter.sv, counter_tb.cpp, Vbuddy.cpp and Vbuddy.cfg into the task 2 folder.
* Connect Vbuddy to the computer's USB port to see the port number and edit Vbuddy.cfg to display S(port number).

### Step 2: Modify testbench for Vbuddy

* Modify the testbench file counter_tb.cpp to include Vbuddy function.
* A list of Vbuddy functions exist which can be included in the testbench file.

![image](https://user-images.githubusercontent.com/21007664/199671922-69855f87-6fe4-4121-a916-004cc96d9bcd.png)

### Step 3: Explore flag feature on Vbuddy

* Vbuddy’s rotary encode has a push-button switch. Vbuddy keeps an internal flag which, by default, will toggle between ‘0’ and ‘1’ each time the button is pressed. 
* Interrogate this toggle switch state with vbdFlag();, which will return its current state and then toggle. A little postbox showing the flag state is drawn in the footer of the TFT display.
* Can use vbdFlag() to enable and disable the counter by modifying the testbench with top->en = vbdFlag()

#### As a counter using vbdHex():

![image](https://user-images.githubusercontent.com/21007664/199241398-c3859342-4883-4b44-a411-5e17cd09b5b9.png)

* Flag is on, counting is on.

![image](https://user-images.githubusercontent.com/21007664/199241280-a49648e5-ff6b-4924-a2d6-030e8c4acb1e.png)

* Flag switched off and counting stops.

![image](https://user-images.githubusercontent.com/21007664/199241323-098ce4fa-f6ed-45aa-80af-035bd1b40a24.png)

#### As a counter using vbdPlot():

* Instead of showing values on the 7-segment display, this can be plotted on the TFT by replacing vbdHex() with vbdPlot(). Increase the number of clock cycles because plotting a dot is much faster than outputting to the 7-segment display.

![image](https://user-images.githubusercontent.com/21007664/199673281-7680c4b4-df2b-4292-a54e-f37b8cd455d9.png)
![image](https://user-images.githubusercontent.com/21007664/199673579-a85438d9-498a-4ea3-8de5-145e42008179.png)

*Flag is on, therefore counting is on so plot increases in value.

![image](https://user-images.githubusercontent.com/21007664/199242081-cd0e980c-26d9-4485-b146-5328e0bf4f73.png)

* Flag is off, so counting stops and plot remains constant.

![image](https://user-images.githubusercontent.com/21007664/199242023-9ebe5998-e38a-4f06-9aa7-1e4db0b9472c.png)

### Challenge: 

Modify your counter and testbench files so that the en signal controls the direction of counting: ‘1’ for up and ‘0’ for down, via the vbdFlag() function.

![image](https://user-images.githubusercontent.com/21007664/199242980-922494e1-217c-420e-b20d-ccd5f28185d8.png)

* If en = 0, we want to decrement. The code above is written for the case when reset = 0 and enable = 0. Here, the count will decrease by 1 due to the count <= count - (the concatenation of 7 0's and a 1 (count = count -1)
* If en = 1, meaning counting like normal, then the other always_ff block is run to allow for the count to increase by 1 each clock cycle.

![image](https://user-images.githubusercontent.com/21007664/199243831-693cef9f-6f8c-4206-8305-3f6daa79d7cb.png)

![image](https://user-images.githubusercontent.com/21007664/199243867-8bee2623-2343-49a3-bdba-8b5741801140.png)
