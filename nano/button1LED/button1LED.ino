
/*
 * Wiring - GND to GND rail
 * Red LED on breadboard
 * D8 to Red LED+
 * 220 ohm Resistor to LED- (one to each)
 * GND rail to Resistor
 * D2 to top of button
 * 3V to power rail
 * power rail to button of button
 */

// constants - these vars wont change
const byte rled = 8; //alias pin D8 to name rled
const byte button = 2; // alias D2 to button

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  pinMode(rled, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(button); // read the state of the button

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(rled, HIGH);
  } else {
    // turn LED off:
    digitalWrite(rled, LOW);
  }
}
