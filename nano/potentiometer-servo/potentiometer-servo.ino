#include <Servo.h>

/* 
 *  Testing potentiometer
 *  GND to GND RAIL
 *  5V to + RAIL
 *  + on Potentiometer to + rail
 *  - on potentiometer to GND rail
 *  Note - potentiometer is 1k
 *  Middle wire on potentiometer to A2
 */

// constants
const byte pot = A2; //alias pin A2 to pot

// vars
int val = 0;

// instantiate servo
Servo myservo;  // create servo object to control a servo

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

}

void loop() {
  val = analogRead(pot);    // read the value from the sensor
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  Serial.println(val);
  delay(15);

}
