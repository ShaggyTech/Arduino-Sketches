/*
---------------------------------------------------------------------------------------

Flex_Sensor_Min_Max by Brandon Eichler
Version 1.0

Source Code: https://github.com/vdubmastertech/Arduino-Sketches

Some portions of this sketch were originally written by SparkFun Electronics,
with lots of help from the Arduino community.
See:  https://github.com/sparkfun/SIK-Guide-Code/blob/master/Circuit_09/Circuit_09.ino
      http://learn.sparkfun.com/products/2 for SIK information.
      http://www.arduino.cc to learn about the Arduino.

This code is completely free for any use.

----------------------------------------------------------------------------------------

** SKETCH PURPOSE:
  Focuses on logging the minimum and maximum readings of a flex sensor.
  This is especially useful if you want to use the map() function on the flex
  sensor reading and need exact upper/lower limits of your specific flex sensor.

** INSTRUCTIONS:
  All you need to do is flex the sensor back and forth and eventually the display
  values will not change, these final readings are the upper/lower limits of 
  that specific flex sensor.  If you want to test another sensor, simply replace
  the current sensor with the new one and reset your arduino board.  Then repeat
  the above to get the new readings.

** FLEX SENSOR
  A flex sensor is a plastic strip with a conductive coating.
  When the strip is straight, the coating will be a certain
  resistance. When the strip is bent, the particles in the coating
  get further apart, increasing the resistance. You can use this
  sensor to sense finger movement in gloves, door hinges, stuffed
  animals, etc. See http://www.sparkfun.com/tutorials/270 for
  more information.
  
** SETTING UP THE FLEX SENSOR
  The flex sensor is the plastic strip with black stripes.
  It senses bending away from the striped side.
  
  The flex sensor has two pins, and since it's a resistor,
  the pins are interchangable.
  
  Connect one of the pins to ANALOG IN pin 0 on the Arduino.
  Connect the same pin, through a 10K Ohm resistor (brown
  black orange) to GND.
  Connect the other pin to 5V.
  
--------------------------------------------------------------------------------------
*/


// Define the analog input pin to measure flex sensor position:
#define flexpin 0

// Initial values for min and max variables
int minFlex = 790;
int maxFlex = 800;

void setup() 
{ 
  // Use the serial monitor window to log the flex sensor values:
  Serial.begin(9600);
} 

/* 
This function takes a single argument, the current flex sensor reading "x", 
and compares it to current values of the minFlex and maxFlex variables.

In other words, it stores the highest and lowest values that
are sensed from the flex sensor and prints them out if the min/max has changed.
*/
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

// Logs the flex sensor min max readings to the serial terminal.
void printMinMax(){
  Serial.print("maxFlex: ");
  Serial.print(maxFlex);
  Serial.print("  minFlex: ");
  Serial.println(minFlex);
  return;
}

void loop() 
{ 
  int flexPosition;    // Input value from the analog pin.
  
  // Read the position of the flex sensor (0 to 1023):  
  flexPosition = analogRead(flexpin);
  
  minMaxFlex(flexPosition); // checks and (if needed) updates the maxFlex and minFlex values
} 
