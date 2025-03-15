#ifndef SERVO_H
#define SERVO_H

#include <Servo.h>

#define onesServoPin 6
#define tensServoPin 5

Servo onesServo;
Servo tensServo;

int startNumber = 0;

void setUpServos();

#endif