/*
  Stepper Motor Demonstration 2
  Stepper-Demo2.ino
  Demonstrates Two 28BYJ-48 Unipolar Steppers with ULN2003 Driver
  Uses Accelstepper Library
 
  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/
 
// Include the AccelStepper Library
#include <AccelStepper.h>
 
// Define Constants
 
// Define step constants

#define HALFSTEP 8
 
// Define Motor Pins (2 Motors used)
 
#define motorPin1  8     // Blue   - 28BYJ48 pin 1
#define motorPin2  9     // Pink   - 28BYJ48 pin 2
#define motorPin3  10    // Yellow - 28BYJ48 pin 3
#define motorPin4  11    // Orange - 28BYJ48 pin 4
                        
                        

// Define two motor objects
// The sequence 1-3-2-4 is required for proper sequencing of 28BYJ48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);

void setup()
{
  // 1 revolution Motor 1 CW
  stepper1.setMaxSpeed(10000000.0);
  stepper1.setAcceleration(100.0);
  stepper1.setSpeed(8000);
  stepper1.moveTo(102400);  
  
 
 
}
 
 
void loop()
{
  //Change direction at the limits
  if (stepper1.distanceToGo() == 0) 
    stepper1.moveTo(-stepper1.currentPosition());
    
  stepper1.run();
 
 
}
