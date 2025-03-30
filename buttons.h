#ifndef BUTTONS_H
#define BUTTONS_H

#include <Adafruit_MCP23X17.h>

#define LED_D4 0
#define LED_D6 1
#define LED_D8 2
#define LED_D10 3
#define LED_D12 4
#define LED_D20 5
#define LED_D100 6

#define BTN_D4 8
#define BTN_D6 9
#define BTN_D8 10
#define BTN_D10 11
#define BTN_D12 12
#define BTN_D20 13
#define BTN_D100 14
#define BTN_RES 15

Adafruit_MCP23X17 mcp;

int numOfLeds = 7;
int ledPins[numOfLeds] = {LED_D4, LED_D6, LED_D8, LED_D10, LED_D12, LED_D20, LED_D100};

int numOfBtns = 8;
int btnPins[numOfBtn] = {BTN_D4, BTN_D6, BTN_D8, BTN_D10, BTN_D12, BTN_D20, BTN_D100, BTN_RES};

void setUpButtons();
void turnOnLed(int led);
void turnOFFLed(int led);
void readBtn();

#endif