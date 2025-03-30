#include "buttons.h"

void setUpButtons()
{
    if (!mcp.begin_I2C(0x27)) {
        Serial.println("Error.");
        while (1);
    }

    // configure pin for output
    for (int i = 0; i < numOfLeds ; i++) {
        mcp.pinMode(ledPins[i], OUTPUT);
    }

    for (int i = 0; i < numOfBtns ; i++) {
        mcp.pinMode(btnPins[i], INPUT_PULLUP);
    }
}

void turnOnLed(int led)
{
    mcp.digitalWrite(led, LOW);
}

void turnOFFLed(int led)
{
    mcp.digitalWrite(led, HIGH);
}

void readBtn()
{

    mcp.digitalRead(BTN_D4);
    mcp.digitalRead(BTN_D6);
    mcp.digitalRead(BTN_D8);
    mcp.digitalRead(BTN_D10);
    mcp.digitalRead(BTN_D12);
    mcp.digitalRead(BTN_D20);
    mcp.digitalRead(BTN_D100);
    mcp.digitalRead(BTN_RES);
}
