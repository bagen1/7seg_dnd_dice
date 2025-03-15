#include "display.h"

void setUpDisplay()
{
  tft.begin();

#if defined(TFT_BL)
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH); // Backlight on
#endif                        // end TFT_BL

  tft.fillScreen(GC9A01A_BLACK);
  tft.setRotation(2);
}

void displayNum(int num)
{
  tft.fillScreen(GC9A01A_BLACK);
  String num_str = String(num);
  if (num < 10)
  {
    tft.setTextColor(GC9A01A_WHITE);
    tft.setTextSize(25);
    tft.setCursor(58, 35);
    if (num == 1)
    {
      tft.fillScreen(GC9A01A_RED);
    }
  }
  else if (num < 20)
  {
    tft.setTextColor(GC9A01A_WHITE);
    tft.setTextSize(18);
    tft.setCursor(15, 55);
  }
  else if (num < 100)
  {
    tft.setTextColor(GC9A01A_WHITE);
    tft.setTextSize(18);
    tft.setCursor(22, 55);
    if (num == 20)
    {
      tft.fillScreen(GC9A01A_GREEN);
      tft.setTextColor(GC9A01A_BLACK);
    }
  }
  else if (num == 100)
  {
    tft.setTextColor(GC9A01A_WHITE);
    tft.setTextSize(12);
    tft.setCursor(15, 75);
  }
  tft.println(num_str);
}
