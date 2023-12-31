#include <FastLED.h>

#define LED_PIN     9   // Change this to the pin connected to the data line of your LED strip
#define NUM_LEDS    1  // Change this to the number of LEDs in your strip

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // Your LED control code goes here
  // For example, to set all LEDs to red:
  fill_solid(leds, NUM_LEDS, CRGB::Red);
  FastLED.show();
  delay(1000);

  // Turn off all LEDs
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  delay(1000);
}
