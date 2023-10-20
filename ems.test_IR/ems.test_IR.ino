// Include Wire Library for I2C
#include <Wire.h>
// Include NewLiquidCrystal Library for I2C
#include <LiquidCrystal_I2C.h>
// Include IRremote Library
#include <IRremote.h>
// Define LCD pinout
const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
 
// Define I2C Address - change if reqiuired
const int i2c_addr = 0x27;
 
LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

//constant to the IR receiver
const int RECV_pin = 2;
IRrecv irrecv(RECV_pin);
decode_results results;

// constants to pushbuttom
int const pushbt = 5;
int const pushbir = 3;
int pushstatet = 0;
int pushstateir = 0;
void setup()
{
  //IR stuff
  Serial.begin(9600);
  //Set pushb pin to receive signal(use 10K ohm to the GND conection)
  pinMode(pushbt, INPUT);
  pinMode(pushbir, INPUT);
  // Set display type as 16 char, 2 rows
  lcd.begin(16,2);

  // Print on first row
  lcd.setCursor(0,0);
  lcd.print("ARCH_test.device");
  
  // Wait 1 second
  delay(1000);
  
  // Print on second row
  lcd.setCursor(0,1);
  lcd.print("4s to start prog");
  
  // Wait 8 seconds
  delay(4000);
  
  // Clear the display
  lcd.clear();
  
  // IR stuff}
  irrecv.enableIRIn();
}
 
 
void loop()
{
  pushstatet = digitalRead(pushbt);
  pushstateir = digitalRead(pushbir);
  irrecv.enableIRIn();
  if(pushstatet == LOW);
{
  lcd.setCursor(0,0);
  lcd.print("press the buttom");
  lcd.setCursor(0,1);
  lcd.print("to simulation");
  
}
  if(pushstatet == HIGH){
  // Demo 1 - flash backlight
  lcd.setCursor(0,0);
  lcd.print("Backlight demo");
  lcd.setCursor(0,1);
  lcd.print("Flash 4 times");
  
  delay(3000);
  lcd.clear();
  
  // Flash backlight 4 times
  for(int i = 0; i< 4; i++)
    {
    lcd.backlight();
    delay(500);
    lcd.noBacklight();
    delay(500);
    }
 
  // Turn backlight back on
  lcd.backlight();
    
  // Demo 2 - scroll
  lcd.setCursor(0,0);
  lcd.print("Scroll demo - ");
  delay(1500);
  // set the display to automatically scroll:
  lcd.autoscroll();
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
    }
  // turn off automatic scrolling
  lcd.noAutoscroll();
 
  // clear screen 
  lcd.clear();
  
  //Delay
  delay(1000);
 
}
if(pushstateir == HIGH){
lcd.clear();
if(irrecv.decode(&results)){
Serial.print(results.value, HEX);
lcd.setCursor(0,0);
lcd.print(results.value, HEX);
irrecv.resume();
delay(1000);
}
}
}
