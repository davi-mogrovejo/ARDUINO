 
// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>
 
// Define sensor pin
const int RECV_PIN = 4;
const int del_1 = 150;
const int del_2 = 2500;
// Define LED pin constants
IRsend irsend;
// Define integer to remember toggle state
int togglestate = 0;
 
// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;
 
 
void setup(){
  // Enable the IR Receiver
  irrecv.enableIRIn();
  // Set LED pins as Outputs
}
 //const int one = 20DF8877;
//const int up = 20DF02FD;
//const int right = 20DF609F;
//const int left = 20DFE01F;
//const int down = 20DF827D;
//const int OK = 20DF22DD;
 
void loop(){
    //if (irrecv.decode(&results)){
 
//if(results.value == 0x20DF8877)
//{
  delay(10000);
        // Turn on LED for 2 Seconds
        irsend.sendNEC(0x20DFE01F, 32); //left
        delay(del_1);
        irsend.sendNEC(0x20DF22DD, 32); //OK
        delay(del_2);
        irsend.sendNEC(0x20DF609F, 32); //right
        delay(del_1);
        irsend.sendNEC(0x20DF22DD, 32); //OK
        delay(del_2);
        irsend.sendNEC(0x20DF827D, 32); //down
        delay(del_1);
        irsend.sendNEC(0x20DFE01F, 32); //left
        delay(del_1);
        irsend.sendNEC(0x20DFE01F, 32); //left
        delay(del_1);
        irsend.sendNEC(0x20DF22DD, 32); //OK
        delay(del_1);
        irsend.sendNEC(0x20DF02FD, 32); //up
        delay(del_1);
        irsend.sendNEC(0x20DF02FD, 32); //up
        delay(del_1);
        irsend.sendNEC(0x20DF609F, 32); //right
        delay(del_1);
        irsend.sendNEC(0x20DF22DD, 32); //OK
        delay(del_1);
        irsend.sendNEC(0x20DF609F, 32); //right
        delay(del_1);
        irsend.sendNEC(0x20DF609F, 32); //right
        delay(del_1);
        irsend.sendNEC(0x20DF609F, 32); //right
        delay(del_1);
        irsend.sendNEC(0x20DF22DD, 32); //OK
        delay(del_1);    
        irsend.sendNEC(0x20DF827D, 32); //down
        delay(del_1);   
        irsend.sendNEC(0x20DF827D, 32); //down
        delay(del_1);   
        irsend.sendNEC(0x20DFE01F, 32); //left
        delay(del_1);   
        irsend.sendNEC(0x20DF22DD, 32); //OK
        delay(del_1);   
        irsend.sendNEC(0x20DFE01F, 32); //left
        delay(del_1);   
        irsend.sendNEC(0x20DFE01F, 32); //left
        delay(del_1);   
        irsend.sendNEC(0x20DFE01F, 32); //left
        delay(del_1);   
        irsend.sendNEC(0x20DF22DD, 32); //OK
        delay(del_1);   
        irsend.sendNEC(0x20DF609F, 32);
        delay(del_1);   
        irsend.sendNEC(0x20DF609F, 32);
        delay(del_1);   
        irsend.sendNEC(0x20DF609F, 32);
        delay(del_1);   
        irsend.sendNEC(0x20DF609F, 32);
        delay(del_1);   
        irsend.sendNEC(0x20DF609F, 32);
        delay(del_1);   
        irsend.sendNEC(0x20DF609F, 32);
        delay(del_1);   
        irsend.sendNEC(0x20DF609F, 32);
        delay(del_1);   
        irsend.sendNEC(0x20DF609F, 32);
        delay(del_1);   
        irsend.sendNEC(0x20DF609F, 32);
        delay(del_1);   
            
        irrecv.resume();
}
//}
//}


