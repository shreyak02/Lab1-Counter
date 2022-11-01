## Task 2: Linking Verilator simulation with Vbuddy

### Step 1: Set up the Vbuddy interface

### Step 2: Modify testbench for Vbuddy

### Step 3: Explore flag feature on Vbuddy

Vbuddy’s rotary encode has a push-button switch. Vbuddy keeps an internal flag which, by default, will toggle between ‘0’ and ‘1’ each time the button is pressed. You can interrogate this toggle switch state with vbdFlag();, which will return its current state and then toggle. A little postbox showing the flag state is drawn in the footer of the TFT display.

As a counter using vbdHex():

![image](https://user-images.githubusercontent.com/21007664/199241398-c3859342-4883-4b44-a411-5e17cd09b5b9.png)

![image](https://user-images.githubusercontent.com/21007664/199241280-a49648e5-ff6b-4924-a2d6-030e8c4acb1e.png)
![image](https://user-images.githubusercontent.com/21007664/199241323-098ce4fa-f6ed-45aa-80af-035bd1b40a24.png)

As a counter using vbdPlot():
![image](https://user-images.githubusercontent.com/21007664/199242081-cd0e980c-26d9-4485-b146-5328e0bf4f73.png)

![image](https://user-images.githubusercontent.com/21007664/199242023-9ebe5998-e38a-4f06-9aa7-1e4db0b9472c.png)

### Challenge: 
Modify your counter and testbench files so that the en signal controls the direction of counting: ‘1’ for up and ‘0’ for down, via the vbdFlag() function.

![image](https://user-images.githubusercontent.com/21007664/199242980-922494e1-217c-420e-b20d-ccd5f28185d8.png)

![image](https://user-images.githubusercontent.com/21007664/199243831-693cef9f-6f8c-4206-8305-3f6daa79d7cb.png)
![image](https://user-images.githubusercontent.com/21007664/199243867-8bee2623-2343-49a3-bdba-8b5741801140.png)
