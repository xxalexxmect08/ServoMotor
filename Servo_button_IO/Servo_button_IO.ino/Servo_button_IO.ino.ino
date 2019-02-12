#include <Servo.h>

Servo Servo1;

Servo Servo2;

int potpin = 0;
int val;
int buttonPin = 2;
int lastState = 0;
int buttonState = 0;
int ledBlu = 12;
int ledRed = 4;

void setup() {
  Servo1.attach (8);
  Servo2.attach (7);
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledBlu, OUTPUT);
  pinMode(ledRed, OUTPUT);

}

void loop() {
  int state = digitalRead(buttonPin);
  if (state == HIGH && state != lastState) {

    buttonState = !buttonState;
  }

  lastState = state;
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 179);
  Serial.println(val);

  if (buttonState == 1) {

digitalWrite(ledRed, HIGH);
digitalWrite(ledBlu, LOW);
    Servo1.write(0);
    Servo2.write(0);
  }
  else {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledBlu, HIGH);
    Servo1.write(val);
    Servo2.write(179 - val);
  }
  delay(15);
}


