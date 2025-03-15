#ifndef DISPLAY_H
#define DISPLAY_H

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_GC9A01A.h"

#define TFT_DC 7
#define TFT_CS 10

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);

void setUpDisplay();
void displayNum(int num);

#endif