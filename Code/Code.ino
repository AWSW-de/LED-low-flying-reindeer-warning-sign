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
String Code_Version = "V1.0.0";


// ###########################################################################################################################################
// # Includes: ! USE THESE LIBRARIES - NOT OTHERS TO AVOID PROBLEMS !
// #
// # You will need to add the following libraries to your Arduino IDE to use the project:
// # - Adafruit NeoPixel      // by Adafruit:                     https://github.com/adafruit/Adafruit_NeoPixel
// #
// ###########################################################################################################################################
#include <Adafruit_NeoPixel.h>  // LED library


// ###########################################################################################################################################
// # Hardware settings:
// ###########################################################################################################################################
// How many LEDs are in your neon LED strip:
#define NUM_LEDS 4
// Data pin - here D5 on the Wemos D1 mini:
#define DATA_PIN 14
// Init LEDs:
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, DATA_PIN, NEO_RGB + NEO_KHZ800);
// Instensity maximum (0-255):
int pixels_intensity = 32;


// ###########################################################################################################################################
// # Startup function:
// ###########################################################################################################################################
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("######################################################################");
  Serial.print("#  startup of version: ");
  Serial.println(Code_Version);
  Serial.println("######################################################################");

  // Initialize the LED strip:
  pixels.begin();

  // Set LED brightness:
  pixels.setBrightness(pixels_intensity);

  // Set all LEDs to red:
  for (int i = 0; i < NUM_LEDS - 1; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
  }
}


// ###########################################################################################################################################
// # Runtime function:
// ###########################################################################################################################################
void loop() {
  for (int i = 0; i <= pixels_intensity; i++) {
    pixels.setBrightness(i);
    pixels.show();
    delay(5);
  }
  delay(250);
  for (int i = pixels_intensity; i >= 0; i = i - 1) {
    pixels.setBrightness(i);
    pixels.show();
    delay(5);
  }
  delay(250);
}


// ###########################################################################################################################################
// # EOF - You have successfully reached the end of the code - well done ;-)
// ###########################################################################################################################################