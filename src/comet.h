

void DrawComet()
{
  const byte fadeAmt = 5;
  const int cometSize = 5;
  const int deltaHue = 4;

  static byte hue = HUE_RED;
  static int iDirection = 1;
  static int iPos = 0;

  hue += deltaHue;

  iPos += iDirection;
  if (iPos == (NUM_LEDS - cometSize) || iPos == 0)
    iDirection *= -1;

  for (int i = 0; i < cometSize; i++)
    smart_lamp_leds[iPos + i].setHue(hue);

  // Randomly fade the LEDs
  for (int j = 0; j < NUM_LEDS; j++)
    if (random(10) > 5)
      smart_lamp_leds[j] = smart_lamp_leds[j].fadeToBlackBy(fadeAmt);

  delay(30);
}
