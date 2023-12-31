// ###########################################################################################################################################
// #
// # Code for the printables "LED low flying reindeer warning sign" project:
// # https://www.printables.com/de/model/700818-led-low-flying-reindeer-warning-sign
// #
// # Code by https://github.com/AWSW-de
// #
// # Released under license: GNU General Public License v3.0: https://github.com/AWSW-de/LED-low-flying-reindeer-warning-sign#GPL-3.0-1-ov-file
// #
// ###########################################################################################################################################


// ###########################################################################################################################################
// # Code version:
// ###########################################################################################################################################
String Code_Version = "V1.1.0";


// ###########################################################################################################################################
// # Includes: ! USE THESE LIBRARIES - NOT OTHERS TO AVOID PROBLEMS !
// #
// # You will need to add the following libraries to your Arduino IDE to use the project:
// # - Adafruit NeoPixel      // by Adafruit:                     https://github.com/adafruit/Adafruit_NeoPixel
// #
// ###########################################################################################################################################
#include <Adafruit_NeoPixel.h>  // LED library


// ###########################################################################################################################################
// # Code settings:
// ###########################################################################################################################################
int UseStartupRGBtest = 1;  // Startup RGB test to check the LEDs
int pixels_intensity = 10;  // Maximum LED instensity (0-255) --> Use low values to save battery power !!!
int flashtime = 75;         // Speed of the flash animation (smaller intensity value --> bigger value for the flashtime)


// ###########################################################################################################################################
// # Hardware settings:
// ###########################################################################################################################################
// How many LEDs are in your neon LED strip:
#define NUM_LEDS 4
// Data pin - here D5 on the Wemos D1 mini:
#define DATA_PIN 14
// Init LEDs:
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);


// ###########################################################################################################################################
// # Startup function:
// ###########################################################################################################################################
void setup() {
  // Initialize the LED strip:
  pixels.begin();

  // Set LED brightness:
  pixels.setBrightness(pixels_intensity);

  // RGB LED test:
  if (UseStartupRGBtest == 1) {
    // Set all LEDs to OFF:
    for (int i = 0; i <= NUM_LEDS - 1; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
    pixels.show();
    delay(1000);

    // Set all LEDs to red:
    for (int i = 0; i <= NUM_LEDS - 1; i++) {
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    }
    pixels.show();
    delay(1000);

    // Set all LEDs to green:
    for (int i = 0; i <= NUM_LEDS - 1; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    }
    pixels.show();
    delay(1000);

    // Set all LEDs to blue:
    for (int i = 0; i <= NUM_LEDS - 1; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    }
    pixels.show();
    delay(1000);
  }

  // Set all LEDs to OFF:
  for (int i = 0; i <= NUM_LEDS - 1; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  pixels.show();
  delay(1000);
}


// ###########################################################################################################################################
// # Runtime function:
// ###########################################################################################################################################
void loop() {
  // Set intensity from 0 to max:
  for (int i = 0; i <= pixels_intensity; i++) {
    pixels.setBrightness(i);
    for (int x = 0; x <= NUM_LEDS - 1; x++) {
      pixels.setPixelColor(x, pixels.Color(255, 0, 0));
    }
    pixels.show();
    delay(flashtime);
  }

  // Set intensity from max to 0:
  for (int i = pixels_intensity; i >= 0; i--) {
    pixels.setBrightness(i);
    for (int x = 0; x <= NUM_LEDS - 1; x++) {
      pixels.setPixelColor(x, pixels.Color(255, 0, 0));
    }
    pixels.show();
    delay(flashtime);
  }
}


// ###########################################################################################################################################
// # EOF - You have successfully reached the end of the code - well done ;-)
// ###########################################################################################################################################