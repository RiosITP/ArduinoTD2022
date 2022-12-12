# Connecting Arduino and TouchDesigner Workshop 2022

## Description
Intro to TouchDesigner and Controlling outputs with arduino via serial communication with buttons, Analog sensors, and/or built-in IMU

This example shows the necessary python scripts, DATs, and CHOPs to set up Serial Communication with an Arduino. This example uses the the free version of TouchDesigner 2022 and the Arduino Nano 33 IoT.

Please come with you Arduino nano 33iot and kit. Please also have Touch Designer and Arduino installed on your machine
* [Touch Designer](https://itp.nyu.edu/physcomp/)

## Arduino Circuit:
This examples can be adjusted for any number of analog or digital inputs or the Nano 33 IoT's built in IMU. 

![Breadboard of Arduino Nano 33 IoT with Buttons connected to D2, D3, D4](imgs/nanobb.png?raw=true "Arduino Nano 33 IoT in a breadboard")

![Breadboard of Arduino Nano 33 IoT with Buttons connected to D2, D3, D4](imgs/arduinoButtons.png?raw=true "Arduino Nano 33 IoT in a breadboard with 3 switches, each connected on one end to pins D2, D3, D4. Each of the switch's other end connects to GND")

![Breadboard of Arduino Nano 33 IoT with Sensors connected to A0, A1, A2](imgs/analogsensors.png?raw=true "Arduino Nano 33 IoT in a breadboard with 2 potentiometers each with pin 1 and 3 connected to GND and 3.3 volts, pin 2 connected to pins A0 and A1 respectively. A photosensor is connected to 3.3 volts on one lead, the other is simulaneously connected to a 10 kilohm pulldown resistor and pin A2.")

## Resources
* [ITP Physical Computing Site](https://itp.nyu.edu/physcomp/)
* [ITP Physical Computing IMU Serial Lab](https://itp.nyu.edu/physcomp/labs/lab-serial-imu-output-to-p5-js/)
* [IMA Designing Interfaces for Live Performance]()

## Further Resources
* [Interactive & Immersive HQ Youtube](https://www.youtube.com/c/TheInteractiveImmersiveHQ)
* [Elburz Sorkhabi and Matthew Ragan's Interactive & Immersive HQ](https://interactiveimmersive.io/)
* [Matthew Ragan's Teaching / Learnign Resources](https://matthewragan.com/teaching-resources/touchdesigner/)
* [Bileam Tschepe's youtube](https://www.youtube.com/channel/UCONptu0J1PCrW9YfBtSdqjA)
* [PPPANIK youtube](https://www.youtube.com/channel/UCWBbakpo_cATqJy9Dzf9x4w)
* [Paketa12 youtube](https://www.youtube.com/user/paketa12)
* [alltd.org](https://alltd.org/)

## Arduino Serial Communication
Read the available sensors and print out the values

    void setup() {
      pinMode(2, INPUT_PULLUP);
      //pinMode(2, INPUT); // Use input if you have 10k resistors
      Serial.begin(9600);
    }

    void loop() {
      int button = digitalRead(2);
      int sensor1 = analogRead(A0);
      int sensor2 = analogRead(A1);

      Serial.print(button);
      Serial.print(',');
      Serial.print(sensor1);
      Serial.print(',');
      Serial.println(sensor2);
    }

## Arduino IMU
If you are using the IMU, make sure you have installed the LSM6DS3 library and the MadgwickAHRS Library from the Library Manager

![Arduino Boards Manager in the v 2.0 IDE](imgs/imu.png "Arduino Boards Manager in the v 2.0 IDE")
![Arduino Boards Manager in the v 2.0 IDE](imgs/madgwick.png "Arduino Boards Manager in the v 2.0 IDE")

## Touch Designer
You can download the sample .toe file from this repo and also follow along with the serial set up below
![Arduino Boards Manager in the v 2.0 IDE](imgs/ "Arduino Boards Manager in the v 2.0 IDE")
