/*
  Madgwick orientation calculation
  Uses Arduino MadgwickAHRS library to calculate heading, pitch, and roll
  on an Arduino Nano 33 IoT, using the onboard LSM6DS3 IMU.
  For big fun, connect this to p5.js sketch MadgwickVisualizer
  created 4 Aug 2019
  updated 25 Aug 2019
  by Tom Igoe

  More here: 
  https://itp.nyu.edu/physcomp/labs/lab-serial-imu-output-to-p5-js/
  https://itpnyu.github.io/physcomp/Labs/LabIMUs/MadgwickVisualizer/
  More on detecting sensor changes here: 
  https://itp.nyu.edu/physcomp/labs/labs-arduino-digital-and-analog/lab-sensor-change-detection/
*/

// IMU LIBRARY for Nano 33 iot (change for other boards)
#include <Arduino_LSM6DS3.h>

// Madgwick Library
#include <MadgwickAHRS.h>

// initialize a Madgwick filter:
Madgwick filter;
// sensor's sample rate is fixed at 104 Hz:
const float sensorRate = 104.00;

// values for orientation:
float twist = 0.0;
float tilt = 0.0;
float turn = 0.0;

void setup() {
  Serial.begin(9600);
  // attempt to start the IMU:
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU");
    // stop here if you can't access the IMU:
    while (true)
      ;
  }
  // start the filter to run at the sample rate:
  filter.begin(sensorRate);
}

void loop() {
  // values for acceleration & rotation:
  float xAcc, yAcc, zAcc;
  float xGyro, yGyro, zGyro;

  // check if the IMU is ready to read:
  if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {
    // read accelerometer & gyrometer:
    IMU.readAcceleration(xAcc, yAcc, zAcc);
    IMU.readGyroscope(xGyro, yGyro, zGyro);

    // update the filter, which computes orientation:
    filter.updateIMU(xGyro, yGyro, zGyro, xAcc, yAcc, zAcc);

    // print the heading, pitch and roll
    twist = filter.getRoll();
    tilt = filter.getPitch();
    turn = filter.getYaw();
    Serial.print(twist);   // twist
    Serial.print(",");     // twist
    Serial.print(tilt);  // twist
    Serial.print(",");
    Serial.println(turn);
  }
}
