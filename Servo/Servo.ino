#include <Servo.h>

Servo Servo1;

Servo Servo2;

int potpin = 0;
int val;
int button=2;
int oldstate=0;

void setup() {
  Servo1.attach (8);
  Servo2.attach (7);
  Serial.begin(9600);
  pinMode(button, INPUT);

}

void loop() {
    val = analogRead(potpin);
    int buttonstate = digitalRead(button);
  val = map(val, 0, 1023, 0, 179);
  Serial.println(val);
  if(buttonstate == 1){
    Servo1.write(0);
    Servo2.write(0);
  }
  else{
  Servo1.write(val);
  Servo2.write(179-val);
  }
 
  delay(15);
  

}
