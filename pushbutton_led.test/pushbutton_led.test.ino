int const led = 7;
int const pushb = 5;
int pushstate = 0;
void setup ()
{
Serial.begin(9600);
pinMode(led, OUTPUT);
pinMode(pushb, INPUT);
}
void loop ()
{
  pushstate = digitalRead(pushb);
  if (pushstate == HIGH)
  {
  digitalWrite(led,HIGH);
  Serial.println("ON");}
  else
  {
    digitalWrite(led, LOW);
    Serial.println("OFF");
  }
}
