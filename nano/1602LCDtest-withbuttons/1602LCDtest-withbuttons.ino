// Include the libraries:
// LiquidCrystal_I2C.h: https://github.com/johnrickman/LiquidCrystal_I2C
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD

// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)
// D2 to top of button 1
// D3 to top of button 2

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Address , width, height

// constants

const byte NUM_CHARS = 16; // define width of display for use in loops
const byte buttonone = 2; // alias D2 to buttonone
const byte buttontwo = 3; // alias D3 to buttontwo

// vars
int buttononeState = 0;
int buttontwoState = 0;

// custom chars
byte block[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

void progress() { // scroll custom char accross the screen like a progress bar
  for (int i = 0; i <= NUM_CHARS-1; i++) {
    lcd.setCursor(i,0); // move cursor using i as position
    lcd.write((byte)0); // write the custom char
    delay(200);
  }
}

void setup() {
  pinMode(buttonone, INPUT);
  pinMode(buttontwo, INPUT);
  // Initiate the LCD:
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, block); // create a new custom character
  progress();
  delay(200);
  lcd.clear();
}


void loop() {
  //read state of buttons
  buttononeState = digitalRead(buttonone); // read the state of the buttonone
  buttontwoState = digitalRead(buttontwo); // read the state of the buttontwo
  if (buttononeState == HIGH) {
    lcd.clear();
    lcd.setCursor(2, 0); // Set the cursor on the third column and first row.
    lcd.print("Hello!");
    delay(1000);
  }
  if (buttontwoState == HIGH) {
    lcd.clear();
    lcd.setCursor(2, 0); // Set the cursor on the third column and first row.
    lcd.print("Goodbye!");
    delay(1000);
  }
}
