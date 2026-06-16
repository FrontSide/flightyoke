// Simple arcade stick example that demonstrates how to read twelve
// Arduino Pro Micro digital pins and map them to the
// Arduino Joystick library.
//

// The digital pins 2 - 20 are grounded when they are pressed.
// Pin 10, A10, Red = UP
// Pin 15, D15, Yellow = RIGHT
// Pin 16, D16, Orange = DOWN
// Pin 14, D14, Green = LEFT

// Pin 9, A9 = Button 1
// Pin 8, A8 = Button 2
// Pin 7, D7 = Button 3
// Pin 3, D3 = Button 4
// Pin 2, D2 = Button 5
// Pin 4, A6 = Button 6

// Pin 20, A2 = Select Button 1
// Pin 19, A1 = Start Button 2

// Pin 5, D5 = Other Button
// Pin 6, A7 = Other Button
// Pin 18, A0 = Other Button
// Pin 21, A3 = Other Button

// NOTE: This sketch file is for use with Arduino Pro Micro only.
//
// Original gamepad example by Matthew Heironimus
// 2016-11-24
// Adapted for arcade machine setup by Ben Parmeter
// 2019-05-20
//--------------------------------------------------------------------

#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  8, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {
   pinMode(21, INPUT_PULLUP); // Potentiometer middle-pin to ADC for Joystick X Axis

  // Initialize Joystick Library
  Joystick.begin();

  //Arduino Micro ADC resolution 1024 
  //The values I enter here are the ADC values from when the controller is in the far left and far right position, respectively.
  //I would be 0, and 1024, respectively, if I used the full range of the potentiometer, but with a steering wheel that's not the case,
  //I only use 180 degrees. 
  Joystick.setXAxisRange(85, 250);  
  Joystick.setYAxisRange(-1, 1);
}

// Last state of the buttons
int lastButtonState[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int buttonMap[16] = {10,15,16,14,9,8,7,3,2,4,20,19,5,6,18,21};

// ButtonMap = 0, Pin 10 = UP
// ButtonMap = 1, Pin 15 = RIGHT
// ButtonMap = 2, Pin 16 = DOWN
// ButtonMap = 3, Pin 14 = LEFT

// ButtonMap = 4, Pin 9 = Button 1
// ButtonMap = 5, Pin 8 = Button 2
// ButtonMap = 6, Pin 7 = Button 3
// ButtonMap = 7, Pin 3 = Button 4
// ButtonMap = 8, Pin 2 = Button 5
// ButtonMap = 9, Pin 4 = Button 6

// ButtonMap = 10, Pin 20 = Select Button 1
// ButtonMap = 11, Pin 19 = Start Button 2

// ButtonMap = 12, Pin 5 = Other Button
// ButtonMap = 13, Pin 6 = Other Button
// ButtonMap = 14, Pin 18 = Other Button
// ButtonMap = 15, Pin 21 = Other Button


void loop() {

  int x = analogRead(21);
  Serial.println(x);
  Joystick.setXAxis(x);
  delay(10);
}