#include <Adafruit_NeoPixel.h>

/*
 * Drive a 16 pixel neopixel ring
 * GND to GND RAIL
 * 5V to + RAIL
 * +RAIL to VCC on neopixel
 * GND RAIL to GN on neopixel
 * D12 to control on neopixel
 * 
 */

 // constants
 const byte NEO = 12; // alias pin 12 for neopixel
 const byte LED_COUNT = 16; // define the number of leds in ring

// create the neopixel ring object. Pass in number of leds, the pin, and the other two
// params depend on which model you have
Adafruit_NeoPixel ring(LED_COUNT, NEO, NEO_GRB + NEO_KHZ800); 

 //define some colours
 uint32_t magenta = ring.Color(255, 0, 255);
 uint32_t green = ring.Color (0, 255, 0);
 uint32_t red = ring.Color (255, 0, 0);
 uint32_t blue = ring.Color (0, 0, 255);

// define some functions

void fill(uint32_t color) { // fill whole ring with one color passed in
  ring.fill(color, 0, LED_COUNT);
  ring.show();
}

void fill_pixel(uint32_t color, int pixel) { // fill one named pixel with color
  ring.clear();
  ring.setPixelColor(pixel, color);
  ring.show();
}

void circle(uint32_t color) { //have the passed in color go round in a loop
    for(int i=0; i < LED_COUNT; i++) { // For each pixel in strip...
    fill_pixel(color, i);         //  Set pixel's color (in RAM)
    ring.show();                          //  Update strip to match
    delay(300);                           //  Pause for a moment
  }
  
}

void setup() {
  ring.begin();
  ring.show(); // Initialize all pixels to 'off'
  ring.setBrightness(50);

}

void loop() {
  circle(red);
}
