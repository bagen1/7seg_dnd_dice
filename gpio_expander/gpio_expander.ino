// Reads a button attached to a MCP23XXX pin.

#include <Adafruit_MCP23X17.h>

#define LED_PIN 0
#define BUTTON_PIN 1  // MCP23XXX pin button is attached to

Adafruit_MCP23X17 mcp;

int ledState = LOW;     // the current state of LED
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button

void setup() {
  Serial.begin(9600);
  Serial.println("Button toggle led Test!");

  // uncomment appropriate mcp.begin
  if (!mcp.begin_I2C(0x27)) {
    Serial.println("Error.");
    while (1);
  }

  // configure pin for input with pull up
  mcp.pinMode(BUTTON_PIN, INPUT_PULLUP);

  currentButtonState = mcp.digitalRead(BUTTON_PIN);
}

void loop() {
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = mcp.digitalRead(BUTTON_PIN);

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    // toggle state of LED
    ledState = !ledState;

    // control LED arccoding to the toggled state
    mcp.digitalWrite(LED_PIN, ledState); 
  }
}