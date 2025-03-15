#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_GC9A01A.h"

// Define pins for display interface. You'll probably need to edit this for
// your own needs:

#if defined(ARDUINO_SEEED_XIAO_RP2040)

// Pinout when using Seed Round Display for XIAO in combination with
// Seeed XIAO RP2040. Other (non-RP2040) XIAO boards, any Adafruit Qt Py
// boards, and other GC9A01A display breakouts will require different pins.
#define TFT_CS D1 // Chip select
#define TFT_DC D3 // Data/command
#define TFT_BL D6 // Backlight control

#else // ALL OTHER BOARDS - EDIT AS NEEDED

// Other RP2040-based boards might not have "D" pin defines as shown above
// and will use GPIO bit numbers. On non-RP2040 boards, you can usually use
// pin numbers silkscreened on the board.
#define TFT_DC 7
#define TFT_CS 10
// If display breakout has a backlight control pin, that can be defined here
// as TFT_BL. On some breakouts it's not needed, backlight is always on.

#endif

// Display constructor for primary hardware SPI connection -- the specific
// pins used for writing to the display are unique to each board and are not
// negotiable. "Soft" SPI (using any pins) is an option but performance is
// reduced; it's rarely used, see header file for syntax if needed.
Adafruit_GC9A01A tft(TFT_CS, TFT_DC);

void setup()
{
    Serial.begin(9600);
    Serial.println("GC9A01A Test!");

    tft.begin();

#if defined(TFT_BL)
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH); // Backlight on
#endif                          // end TFT_BL

    tft.fillScreen(GC9A01A_BLACK);
    tft.setRotation(2);
    tft.setCursor(50, 110);
    tft.setTextColor(GC9A01A_WHITE);
    tft.setTextSize(2);
    tft.println("Hello World!");
    delay(500);
}

void loop()
{
    for (int i = 1; i <= 100; i++)
    {
        tft.fillScreen(GC9A01A_BLACK);
        String num_str = String(i);
        if (i < 10)
        {
            tft.setTextColor(GC9A01A_WHITE);
            tft.setTextSize(25);
            tft.setCursor(58, 35);
            if (i == 1)
            {
                tft.fillScreen(GC9A01A_RED);
            }
        }
        else if (i < 20)
        {
            tft.setTextColor(GC9A01A_WHITE);
            tft.setTextSize(18);
            tft.setCursor(15, 55);
        }
        else if (i < 100)
        {
            tft.setTextColor(GC9A01A_WHITE);
            tft.setTextSize(18);
            tft.setCursor(22, 55);
            if (i == 20)
            {
                tft.fillScreen(GC9A01A_GREEN);
                tft.setTextColor(GC9A01A_BLACK);
            }
        }
        else if (i == 100)
        {
            tft.setTextColor(GC9A01A_WHITE);
            tft.setTextSize(12);
            tft.setCursor(15, 75);
        }
        tft.println(num_str);
        Serial.println(num_str);
        delay(600);
    }
}
