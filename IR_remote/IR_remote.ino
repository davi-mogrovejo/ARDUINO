#include <IRremote.h>

const int RECV_pin = 2;

IRrecv irrecv(RECV_pin);
decode_results results;
void setup(){
    Serial.begin(9600);
    irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&results)){
    Serial.println(results.value,HEX);
    irrecv.resume();
  }
}
