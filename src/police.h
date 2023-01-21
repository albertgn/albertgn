

int strobo_1 = 30;
int strobo_2 = 80;
int strobo_3 = 50;
int strobo_4 = 100;

int freq_1 = 10;
int freq_2 = 30;
int freq_3 = 100;

int freq_pattern_1 = 40;

void rosso()
{

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j < 34; j++)
        {
            smart_lamp_leds[j] = CRGB(255, 0, 0);
        }

        FastLED.show();
        delay(strobo_1);

        FastLED.clear();
        delay(strobo_1);

        FastLED.show();
        delay(strobo_1);
    }
}

void bianco()
{

    for (int i = 0; i <= 3; i++)
    {

        for (int j = 34; j < 67; j++)
        {
            smart_lamp_leds[j] = CRGB(255, 255, 255);
        }

        FastLED.show();
        delay(strobo_1);

        FastLED.clear();
        delay(strobo_1);

        FastLED.show();
        delay(strobo_1);
    }
}

void blu()
{

    for (int i = 0; i <= 3; i++)
    {

        for (int j = 67; j < 100; j++)
        {
            smart_lamp_leds[j] = CRGB(0, 0, 255);
        }

        FastLED.show();
        delay(strobo_1);

        FastLED.clear();
        delay(strobo_1);

        FastLED.show();
        delay(strobo_1);
    }
}

void mix_rwb()
{

    for (int i = 0; i <= 6; i++)
    {

        for (int j = 0; j < 34; j++)
        {
            smart_lamp_leds[j] = CRGB(255, 0, 0);
        }

        for (int j = 34; j < 67; j++)
        {
            smart_lamp_leds[j] = CRGB(255, 255, 255);
        }

        for (int j = 67; j < 100; j++)
        {
            smart_lamp_leds[j] = CRGB(0, 0, 255);
        }


        FastLED.show();
        delay(strobo_1);

        FastLED.clear();
        delay(strobo_1);

        FastLED.show();
        delay(strobo_1);
    }
}

void mix_rb()
{

    for (int i = 0; i <= 3; i++)
    {
                for (int j = 0; j < 34; j++)
        {
            smart_lamp_leds[j] = CRGB(255, 0, 0);
        }

        FastLED.show();
        delay(strobo_1);
        FastLED.clear();
        delay(strobo_1);

        FastLED.show();
        delay(strobo_1);
        FastLED.clear();
        delay(strobo_1);
    }

    for (int i = 0; i <= 3; i++)
    {

        for (int j = 67; j < 100; j++)
        {
            smart_lamp_leds[j] = CRGB(0, 0, 255);
        }

        FastLED.show();
        delay(strobo_1);
        FastLED.clear();
        delay(strobo_1);

        FastLED.show();
        delay(strobo_1);
        FastLED.clear();
        delay(strobo_1);
    }
}

void mix_rl_lr()
{

    for (int i = 0; i <= 3; i++)
    {

        for (int j = 0; j < 34; j++)
        {
            smart_lamp_leds[j] = CRGB(255, 0, 0);
        }


        for (int j = 67; j < 100; j++)
        {
            smart_lamp_leds[j] = CRGB(0, 0, 255);
        }

        FastLED.show();
        delay(strobo_1);
        FastLED.clear();
        delay(strobo_1);
    }

    for (int i = 0; i <= 3; i++)
    {

        for (int j = 0; j < 34; j++)
        {
            smart_lamp_leds[j] = CRGB(255, 0, 0);
        }



        for (int j = 67; j < 100; j++)
        {
            smart_lamp_leds[j] = CRGB(0, 0, 255);
        }

        FastLED.show();
        delay(strobo_1);
        FastLED.clear();
        delay(strobo_1);
    }
}

void mix_rl_w_lr()
{

    for (int i = 0; i <= 3; i++)
    {

        smart_lamp_leds[0] = CRGB::Red;
        smart_lamp_leds[1] = CRGB::Red;
        smart_lamp_leds[2] = CRGB::Red;
        smart_lamp_leds[3] = CRGB::Red;
        smart_lamp_leds[4] = CRGB::Red;

        smart_lamp_leds[10] = CRGB::White;
        smart_lamp_leds[11] = CRGB::White;
        smart_lamp_leds[12] = CRGB::White;
        smart_lamp_leds[13] = CRGB::White;
        smart_lamp_leds[14] = CRGB::White;

        smart_lamp_leds[15] = CRGB::White;
        smart_lamp_leds[16] = CRGB::White;
        smart_lamp_leds[17] = CRGB::White;
        smart_lamp_leds[18] = CRGB::White;

        smart_lamp_leds[25] = CRGB::Blue;
        smart_lamp_leds[26] = CRGB::Blue;
        smart_lamp_leds[27] = CRGB::Blue;
        smart_lamp_leds[28] = CRGB::Blue;
        smart_lamp_leds[29] = CRGB::Blue;

        FastLED.show();
        delay(strobo_1);
        FastLED.clear();
        delay(strobo_1);
    }

    for (int i = 0; i <= 3; i++)
    {

        smart_lamp_leds[5] = CRGB::Red;
        smart_lamp_leds[6] = CRGB::Red;
        smart_lamp_leds[7] = CRGB::Red;
        smart_lamp_leds[8] = CRGB::Red;
        smart_lamp_leds[9] = CRGB::Red;

        smart_lamp_leds[10] = CRGB::Black;
        smart_lamp_leds[11] = CRGB::Black;
        smart_lamp_leds[12] = CRGB::Black;
        smart_lamp_leds[13] = CRGB::Black;
        smart_lamp_leds[14] = CRGB::Black;

        smart_lamp_leds[15] = CRGB::Black;
        smart_lamp_leds[16] = CRGB::Black;
        smart_lamp_leds[17] = CRGB::Black;
        smart_lamp_leds[18] = CRGB::Black;

        smart_lamp_leds[19] = CRGB::Blue;
        smart_lamp_leds[20] = CRGB::Blue;
        smart_lamp_leds[21] = CRGB::Blue;
        smart_lamp_leds[22] = CRGB::Blue;
        smart_lamp_leds[23] = CRGB::Blue;

        FastLED.show();
        delay(strobo_1);
        FastLED.clear();
        delay(strobo_1);
    }
}

//*********************************************************************

void rosso_static()
{

    smart_lamp_leds[0] = CRGB(255, 0, 0);
    smart_lamp_leds[1] = CRGB(255, 0, 0);
    smart_lamp_leds[2] = CRGB(255, 0, 0);
    smart_lamp_leds[3] = CRGB(255, 0, 0);
    smart_lamp_leds[4] = CRGB(255, 0, 0);
    smart_lamp_leds[5] = CRGB(255, 0, 0);
    smart_lamp_leds[6] = CRGB(255, 0, 0);
    smart_lamp_leds[7] = CRGB(255, 0, 0);
    smart_lamp_leds[8] = CRGB(255, 0, 0);
    smart_lamp_leds[9] = CRGB(255, 0, 0);

    FastLED.show();
    delay(strobo_3);

    FastLED.clear();
    delay(strobo_3);
}

void bianco_static()
{

    smart_lamp_leds[10] = CRGB(255, 255, 255);
    smart_lamp_leds[11] = CRGB(255, 255, 255);
    smart_lamp_leds[12] = CRGB(255, 255, 255);
    smart_lamp_leds[13] = CRGB(255, 255, 255);
    smart_lamp_leds[14] = CRGB(255, 255, 255);
    smart_lamp_leds[15] = CRGB(255, 255, 255);
    smart_lamp_leds[16] = CRGB(255, 255, 255);
    smart_lamp_leds[17] = CRGB(255, 255, 255);
    smart_lamp_leds[18] = CRGB(255, 255, 255);

    FastLED.show();
    delay(strobo_3);

    FastLED.clear();
    delay(strobo_3);
}

void blu_static()
{

    smart_lamp_leds[19] = CRGB(0, 0, 255);
    smart_lamp_leds[20] = CRGB(0, 0, 255);
    smart_lamp_leds[21] = CRGB(0, 0, 255);
    smart_lamp_leds[22] = CRGB(0, 0, 255);
    smart_lamp_leds[23] = CRGB(0, 0, 255);
    smart_lamp_leds[24] = CRGB(0, 0, 255);
    smart_lamp_leds[25] = CRGB(0, 0, 255);
    smart_lamp_leds[26] = CRGB(0, 0, 255);
    smart_lamp_leds[27] = CRGB(0, 0, 255);
    smart_lamp_leds[28] = CRGB(0, 0, 255);
    smart_lamp_leds[29] = CRGB(0, 0, 255);

    FastLED.show();
    delay(strobo_3);

    FastLED.clear();
    delay(strobo_3);
}

// §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Pattern 1

void pattern_1()
{

    for (int i = 0; i <= 3; i++)
    {

        smart_lamp_leds[0] = CRGB(255, 0, 0);
        smart_lamp_leds[1] = CRGB(255, 0, 0);
        smart_lamp_leds[2] = CRGB(255, 0, 0);
        smart_lamp_leds[3] = CRGB(255, 0, 0);
        smart_lamp_leds[4] = CRGB(255, 0, 0);

        smart_lamp_leds[25] = CRGB(0, 0, 255);
        smart_lamp_leds[26] = CRGB(0, 0, 255);
        smart_lamp_leds[27] = CRGB(0, 0, 255);
        smart_lamp_leds[28] = CRGB(0, 0, 255);
        smart_lamp_leds[29] = CRGB(0, 0, 255);

        FastLED.show();
        delay(freq_pattern_1);
        FastLED.clear();
        delay(freq_pattern_1);
    }

    for (int i = 0; i <= 3; i++)
    {

        smart_lamp_leds[5] = CRGB(255, 0, 0);
        smart_lamp_leds[6] = CRGB(255, 0, 0);
        smart_lamp_leds[7] = CRGB(255, 0, 0);
        smart_lamp_leds[8] = CRGB(2550, 0, 0);
        smart_lamp_leds[9] = CRGB(2550, 0, 0);

        smart_lamp_leds[19] = CRGB(0, 0, 255);
        smart_lamp_leds[20] = CRGB(0, 0, 255);
        smart_lamp_leds[21] = CRGB(0, 0, 255);
        smart_lamp_leds[22] = CRGB(0, 0, 255);
        smart_lamp_leds[23] = CRGB(0, 0, 255);

        FastLED.show();
        delay(freq_pattern_1);
        FastLED.clear();
        delay(freq_pattern_1);
    }
}

// Pattern 2

void pattern_2()
{

    for (int i = 0; i <= 3; i++)
    {

        smart_lamp_leds[0] = CRGB(255, 0, 0);
        smart_lamp_leds[1] = CRGB(255, 0, 0);
        smart_lamp_leds[2] = CRGB(255, 0, 0);
        smart_lamp_leds[3] = CRGB(255, 0, 0);
        smart_lamp_leds[4] = CRGB(255, 0, 0);

        smart_lamp_leds[25] = CRGB(0, 0, 255);
        smart_lamp_leds[26] = CRGB(0, 0, 255);
        smart_lamp_leds[27] = CRGB(0, 0, 255);
        smart_lamp_leds[28] = CRGB(0, 0, 255);
        smart_lamp_leds[29] = CRGB(0, 0, 255);

        FastLED.show();
        delay(freq_pattern_1);
        FastLED.clear();
        delay(freq_pattern_1);
    }

    for (int i = 0; i <= 3; i++)
    {

        smart_lamp_leds[5] = CRGB(255, 0, 0);
        smart_lamp_leds[6] = CRGB(255, 0, 0);
        smart_lamp_leds[7] = CRGB(255, 0, 0);
        smart_lamp_leds[8] = CRGB(2550, 0, 0);
        smart_lamp_leds[9] = CRGB(2550, 0, 0);

        smart_lamp_leds[19] = CRGB(0, 0, 255);
        smart_lamp_leds[20] = CRGB(0, 0, 255);
        smart_lamp_leds[21] = CRGB(0, 0, 255);
        smart_lamp_leds[22] = CRGB(0, 0, 255);
        smart_lamp_leds[23] = CRGB(0, 0, 255);

        FastLED.show();
        delay(freq_pattern_1);
        FastLED.clear();
        delay(freq_pattern_1);
    }
}

//****************************************************************

void white_blink()
{

    for (int i = 0; i <= 3; i++)
    {

        // smart_lamp_leds[10]=CRGB (255,255,255);
        // smart_lamp_leds[11]=CRGB (255,255,255);
        // smart_lamp_leds[12]=CRGB (255,255,255);

        smart_lamp_leds[13] = CRGB(255, 255, 255);
        smart_lamp_leds[14] = CRGB(255, 255, 255);
        smart_lamp_leds[15] = CRGB(255, 255, 255);

        // smart_lamp_leds[16]=CRGB (255,255,255);
        // smart_lamp_leds[17]=CRGB (255,255,255);
        // smart_lamp_leds[18]=CRGB (255,255,255);

        FastLED.show();
        delay(freq_pattern_1);
        FastLED.clear();
        delay(freq_pattern_1);

        smart_lamp_leds[10] = CRGB(255, 255, 255);
        smart_lamp_leds[11] = CRGB(255, 255, 255);
        smart_lamp_leds[12] = CRGB(255, 255, 255);

        // smart_lamp_leds[13]=CRGB (255,255,255);
        // smart_lamp_leds[14]=CRGB (255,255,255);
        // smart_lamp_leds[15]=CRGB (255,255,255);

        smart_lamp_leds[16] = CRGB(255, 255, 255);
        smart_lamp_leds[17] = CRGB(255, 255, 255);
        smart_lamp_leds[18] = CRGB(255, 255, 255);

        FastLED.show();
        delay(freq_pattern_1);
        FastLED.clear();
        delay(freq_pattern_1);
    }
}
// §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//***************************************************
//***************************************************
//***************************************************
//***************************************************
//***************************************************
//***************************************************

void police()
{

    //--------------------------------------- STEP 1
    rosso();
    delay(strobo_2);

    blu();
    delay(strobo_2);

    rosso();
    delay(strobo_2);

    blu();
    delay(strobo_2);

    //-------------------------------------- STEP 2

    mix_rwb();
    delay(strobo_2);

    //-------------------------------------- STEP 3

    //-------------------------------------- STEP 4

    mix_rb();
    delay(strobo_2);

    //-------------------------------------- STEP 5

    for (int i = 0; i <= 3; i++)
    {
        mix_rl_lr();
        delay(strobo_1);
    }

    //-------------------------------------- STEP 6

    bianco();
    delay(strobo_2);

    //-------------------------------------- STEP 7

    for (int i = 0; i <= 6; i++)
    {
        mix_rl_w_lr();
        delay(strobo_1);
    }

    //-------------------------------------- STEP 8

    for (int i = 0; i <= 6; i++)
    {
        rosso();
        delay(strobo_2);

        blu();
        delay(strobo_2);

        rosso();
        delay(strobo_2);

        blu();
        delay(strobo_2);
    }

    //-----------------------------------  STEP 11

    for (int i = 0; i <= 6; i++)
    {
        pattern_1();
    }

    //------------------------------------ STEP 12

    for (int i = 0; i <= 6; i++)
    {
        pattern_2();
    }

    //----------------------------------- STEP 10

    white_blink();

    //

    //------------------------------------- STEP 9

    //------------------------------------ STEP 14

    for (int i = 0; i <= 6; i++)
    {

        for (int i = 0; i <= 3; i++)
        {

            for (int i = 29; i >= 0; i--)
            {
                smart_lamp_leds[i] = CRGB::Red;
                FastLED.show();
            }

            FastLED.clear();
        }

        for (int i = 0; i <= 3; i++)
        {

            for (int i = 0; i <= 29; i++)
            {
                smart_lamp_leds[i] = CRGB::White;
                FastLED.show();
            }
            FastLED.clear();
        }

        for (int i = 0; i <= 3; i++)
        {

            for (int i = 0; i <= 29; i++)
            {
                smart_lamp_leds[i] = CRGB::Blue;
                FastLED.show();
            }
            FastLED.clear();
        }
    }

    //----------------------------------- STEP 15
}
