/*
SparkFun Inventor's Kit
Example sketch 09

FLEX SENSOR

  Use the "flex sensor" to change the position of a servo
  
  In the previous sketch, we learned how to command a servo to
  mode to different positions. In this sketch, we'll introduce
  a new sensor, and use it to control the servo.
  
  A flex sensor is a plastic strip with a conductive coating.
  When the strip is straight, the coating will be a certain
  resistance. When the strip is bent, the particles in the coating
  get further apart, increasing the resistance. You can use this
  sensor to sense finger movement in gloves, door hinges, stuffed
  animals, etc. See http://www.sparkfun.com/tutorials/270 for
  more information.
  
Hardware connections:

  Flex sensor:

    The flex sensor is the plastic strip with black stripes.
    It senses bending away from the striped side.
    
    The flex sensor has two pins, and since it's a resistor,
    the pins are interchangable.
    
    Connect one of the pins to ANALOG IN pin 0 on the Arduino.
    Connect the same pin, through a 10K Ohm resistor (brown
    black orange) to GND.
    Connect the other pin to 5V.

  Servo:
  
    The servo has a cable attached to it with three wires.
    Because the cable ends in a socket, you can use jumper wires
    to connect between the Arduino and the servo. Just plug the
    jumper wires directly into the socket.
    
    Connect the RED wire (power) to 5 Volts (5V)
    Connect the WHITE wire (signal) to digital pin 9
    Connect the BLACK wire (ground) to ground (GND)
  
    Note that servos can use a lot of power, which can cause your
    Arduino to reset or behave erratically. If you're using large
    servos or many of them, it's best to provide them with their
    own separate 5V supply. See this Arduino Forum thread for info:
    http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1239464763

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/


// Include the servo library to add servo-control functions:

#include <Servo.h> 

// Create a servo "object", called servo1. Each servo object
// controls one servo (you can have a maximum of 12):

Servo servo1;

// Define the analog input pin to measure flex sensor position:

const int flexpin = 0; 
int maxFlex = 800;
int minFlex = 700;
int maxServo = 60;
int minServo = 50;

void setup() 
{ 
  // Use the serial monitor window to help debug our sketch:
   
  Serial.begin(9600);
  
  // Enable control of a servo on pin 9:

  servo1.attach(9);
} 

void minMaxFlex(int x){
  if (x < minFlex){
    minFlex = x;
    printMinMax();
    return;
  }
  else if (x > maxFlex){
    maxFlex = x;
    printMinMax();
    return;
  }
  else {
    return;
  }
}

void minMaxServo(int x){
  if (x < minServo){
    minServo = x;
    printMinMax();
    return;
  }
  else if (x > maxServo){
    maxServo = x;
    printMinMax();
    return;
  }
  else {
    return;
  }
}

void printMinMax(){
  Serial.print("maxFlex:  ");
  Serial.print(maxFlex);
  Serial.print("  minFlex:  ");
  Serial.print(minFlex);
  Serial.print("  maxServo:  ");
  Serial.print(maxServo);
  Serial.print("  minServo:  ");
  Serial.println(minServo);
  return;
}

void loop() 
{ 
  int flexPosition;    // Input value from the analog pin.
  int servoPosition;   // Output value to the servo.
  
  // Read the position of the flex sensor (0 to 1023):
  
  flexPosition = analogRead(flexpin);
  
  minMaxFlex(flexPosition);
  minMaxServo(servoPosition);

  // Because the voltage divider circuit only returns a portion
  // of the 0-1023 range of analogRead(), we'll map() that range
  // to the servo's range of 0 to 180 degrees. The flex sensors
  // we use are usually in the 600-900 range:
  
  servoPosition = map(flexPosition, minFlex, maxFlex, 0, 180);
  servoPosition = constrain(servoPosition, 0, 180);

  // Now we'll command the servo to move to that position:

  servo1.write(servoPosition);

  // Because every flex sensor has a slightly different resistance,
  // the 600-900 range may not exactly cover the flex sensor's
  // output. To help tune our program, we'll use the serial port to
  // print out our values to the serial monitor window:
  
  //Serial.print("sensor: ");
  //Serial.print(flexposition);
  //Serial.print("  servo: ");
  //Serial.println(servoposition);
  
  delay(20);  // wait 20ms between servo updates
} 



