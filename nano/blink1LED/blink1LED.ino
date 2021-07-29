/*
 * Wiring - GND to GND rail
 * D8 to LED+
 * 220 ohm Resistor to LED-
 * GND rail to Resistor
 */



void setup() {
  pinMode(8, OUTPUT);

}

void loop() {
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 

}
