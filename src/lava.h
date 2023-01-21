#include <FastLED.h>
uint16_t indexScale = 100;
uint16_t brightnessScale = 150;

// variables to control the lamp from Blynk
int lava = 0, lavablue = 0;
void runLava()
{

  FastLED.clear();
  FastLED.show();
  for (int i = 0; i < NUM_LEDS; i++)
  {
    uint8_t brightness = inoise8(i * brightnessScale, millis() / 5);
    uint8_t index = inoise8(i * indexScale, millis() / 10);
    smart_lamp_leds[i] = ColorFromPalette(lavaPalette, index, brightness);
  }

  FastLED.show();
}

void runLavaBlue()
{

  Serial.println("playing blue lava");
  FastLED.clear();
  FastLED.show();
  for (int i = 0; i < NUM_LEDS; i++)
  {
    uint8_t brightness = inoise8(i * brightnessScale, millis() / 5);
    uint8_t index = inoise8(i * indexScale, millis() / 10);
    smart_lamp_leds[i] = ColorFromPalette(lavaPaletteBlue, index, brightness);
  }

  FastLED.show();
}