#include <Stepper.h>
const float STEPS_PER_REV = 32; 
const float GEAR_RED = 64;
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;
int StepsRequired;
int analogPin = A0;
int sensorr = 0; 
Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);
 
void setup()
{
Serial.begin(9600);
}
 
void loop(){
  sensorr = analogRead(analogPin);
  Serial.println(sensorr); 
 while(sensorr <= 1000){
  StepsRequired  =  STEPS_PER_OUT_REV * 1/2 ; 
  steppermotor.setSpeed(1000);   
  steppermotor.step(StepsRequired);
delay(1000);
 }
}
