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

void setup() {
  Serial.begin(9600);

}

void loop() {
  val = analogRead(pot);    // read the value from the sensor
  Serial.println(val);
  delay(500);
}
