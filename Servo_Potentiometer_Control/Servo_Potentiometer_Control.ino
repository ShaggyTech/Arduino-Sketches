#include <Servo.h>
Servo servo1;
const int potPin = 0;

void setup() {

servo1.attach(9);
Serial.begin(9600);

}

void loop() {
  
int potValue;
int servoPosition;

potValue = analogRead(potPin);

servoPosition = map(potValue, 0, 1023, 0, 179);
servoPosition = constrain(servoPosition, 10, 170);

servo1.write(servoPosition);
delay(40);

Serial.print("Potentiometer Reading: ");
Serial.print(potValue);
Serial.print("  Servo Position: ");
Serial.println(servoPosition);

}
