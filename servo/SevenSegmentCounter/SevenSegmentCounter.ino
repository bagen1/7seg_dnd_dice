 /*
 7 Segment Display Counter
This Code will count up starting at the start number set below.
You can change the delay to change how fast it takes to count up.
 */

#include <Servo.h>
#include "Arduino_LED_Matrix.h"
#include "fonts.h"
ArduinoLEDMatrix matrix;

uint8_t frame[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

Servo onesMotor;
Servo tensMotor;

int startNumber = 0;
int countDelay = 5000;

// the setup routine runs once when you press reset:
void setup() {
  
  onesMotor.write((startNumber%10)*20); 
  // tensMotor.write((startNumber/10)*20);

  onesMotor.attach(6);
  // tensMotor.attach(4);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  delay(1500);
  matrix.begin();
}

// the loop routine runs over and over again forever:
void loop() {
  delay(countDelay);
  startNumber++;
  Serial.println(startNumber);
  onesMotor.write((startNumber%10)*20); 
  // tensMotor.write(((startNumber/10)%10)*20);
  if (startNumber == 10)
  {
    startNumber = 0;
  }
  char c = '0' + startNumber;
  clear_frame();
  add_to_frame(c, 4);
  display_frame();
}

void clear_frame() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 12; col++) {
      frame[row][col] = 0;
    }
  }
}

void display_frame() {
  matrix.renderBitmap(frame, 8, 12);
}

void add_to_frame(char c, int pos) {
  int index = -1;
  if (c >= '0' && c <= '9')
    index = c - '0';
  else if (c >= 'A' && c <= 'Z')
    index = c - 'A' + 10;
  else {
    Serial.println("WARNING: unsupported character");
    return;
  }

  for (int row = 0; row < 8; row++) {
    uint32_t temp = fonts[index][row] << (7 - pos);
    for (int col = 0; col < 12; col++) {
      frame[row][col] |= (temp >> (11 - col)) & 1;
    }
  }
}
