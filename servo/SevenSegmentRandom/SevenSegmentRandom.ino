 /*
  7 Segment Random Number Generator
  Uses a button input to trigger a random number generator
  This code works with up to 3 modules but you can add as many as you would like of course!
  This can be used as a dice to play board games, or whatever else you think might be fun.
 */

#include <Servo.h>

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;

Servo onesMotor;
Servo tensMotor;

// the setup routine runs once when you press reset:
void setup() {
  onesMotor.write(7*20); 
  tensMotor.write(9*20);

  onesMotor.attach(6);
  tensMotor.attach(4);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT_PULLUP);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);

  if(buttonState == 0){ //May need to change this depending on how you've wired your button
    
    //Create a random scrolling effect
    onesMotor.write(9*20);
    tensMotor.write(9*20);
    delay(400);
    onesMotor.write(0);
    tensMotor.write(0);
    delay(400);

    //Select a random number and show it
    onesMotor.write(random(0,9)*20);
    tensMotor.write(random(0,9)*20);    
  }
  
}
