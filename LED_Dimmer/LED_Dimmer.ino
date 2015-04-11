// Global variables
int ledPin = 12;   // redboard pin the + leg of the led is connected to
int analogPin = 3;    // redboard pin the middle leg of the potentiometer is connected to
int val = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(analogPin);
analogWrite(ledPin, val / 4);
}
