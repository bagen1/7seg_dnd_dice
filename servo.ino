#include "servo.h"

void setUpServos()
{
  onesServo.write((startNumber % 10) * 20);
  // tensServo.write((startNumber % 10) * 20);

  onesServo.attach(6);
  // tensServo.attach(5);
}