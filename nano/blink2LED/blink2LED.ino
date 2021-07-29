/*
 * Wiring - GND to GND rail
 * Red LED on breadboard
 * Yellow LED on breadboard
 * D8 to Red LED+
 * D7 to Yellow LED+
 * 220 ohm Resistor to LED- (one to each)
 * GND rail to Resistor
 */

const byte rled = 8
const byte yled = 7

void setup() {
  pinMode(rled, OUTPUT);
  pinMode(yled, OUTPUT);

}

void loop() {
  digitalWrite(rled, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(rled, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
  digitalWrite(yled, HIGH);
  delay(1000);
  digitalWrite(yled,LOW);
  delay(1000);

}
