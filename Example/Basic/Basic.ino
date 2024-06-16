/*
  Stepper motor driver
  Demonstrates a full revolution of a 28BYJ-48 Stepper Motor
  The circuit:
   ULN2006 module
   28BYJ-48 Stepper Motor
  Description:
  As this motor has an internal gear box,the number of steps for one revolution is 2048

  Created by S.S. Abeywickrama
  Date: 06 Jul 2024
  Tested and verified
  
  This example code is in the public domain.
  You may use or modify this code.

*/

#include "SSM_Stepper.h"         // Include the library

// Initialize the stepper motor object with motor driven pins 9, 10, 11, 12
SSM_Stepper Stepper1(9, 10, 11, 12); 

void setup() {
  // No initialization required for setup
}

void loop() {
  // Run the stepper motor
  // Stepper1.runStepper(#steps, direction (set 1 for CW / set 0 for CCW), inter-step delay in ms)
  // After this function, the motor runs as per the given parameters and then stops the current conduction
  // This saves power and reduces temperature
  Stepper1.runStepper(2048, 1, 4); 
  delay(1000);  // Wait for 1 second before running the motor again
}
