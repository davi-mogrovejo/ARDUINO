#include <Stepper.h>
const float STEPS_PER_REV = 32; 
const float GEAR_RED = 64;
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;
int StepsRequired;
int analogPin = A0;
int sensorr = 0; 
int i = 0;
int j = 0;
Stepper steppermotor(STEPS_PER_REV, 9, 11, 10, 12);
void setup()
{
Serial.begin(9600);
}
 
void loop(){
  sensorr = analogRead(analogPin);
  Serial.println(sensorr); 
 if(sensorr <= 1000){
 while(i++ < 2){
  StepsRequired  =  STEPS_PER_OUT_REV * 1/2 * (4); //if = * 1/2, turns 360°
  steppermotor.setSpeed(700);   
  steppermotor.step(StepsRequired);
  (j = j*0);
} 
}
if(sensorr > 1000){
  while(j++ < 2){
  StepsRequired  = - STEPS_PER_OUT_REV * 1/2 * (4) ; //if = * 1/2, turns 360°
  steppermotor.setSpeed(700);   
  steppermotor.step(StepsRequired);
  (i = i*0); 
}
}
}
