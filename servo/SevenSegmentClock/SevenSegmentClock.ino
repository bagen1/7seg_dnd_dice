 /*
  7 Segment Clock Code 
  Uses a DS3231 Real Time Clock Module (I used this one: https://geni.us/rtKYLJT) and displays the time.
  Note you need the DS3231 Library from Andrew Wickert (https://github.com/NorthernWidget/DS3231)
  There is an example code in there to set the real time clock, then it just outputs the data!
*/


 
#include <Wire.h>
#include <DS3231.h>
#include <Servo.h>

RTClib myRTC;

Servo secondsOnes;
Servo secondsTens;
Servo minutesOnes;
Servo minutesTens;
Servo hoursOnes;
Servo hoursTens;

String inString = "";



void setup()
{
  secondsOnes.write(0); 
  secondsTens.write(0);
  minutesOnes.write(0);
  minutesTens.write(0);
  hoursOnes.write(0);
  hoursTens.write(0);
  
  secondsOnes.attach(2);
  secondsTens.attach(3);
  minutesOnes.attach(4);
  minutesTens.attach(5);
  hoursOnes.attach(6);
  hoursTens.attach(7);

  Serial.begin(57600);
  Wire.begin();
  delay(500);
  Serial.println("Seven Segment Clock Begin");
}

void loop() {

  delay(1000);
  DateTime now = myRTC.now();

  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();


  //Split the secondss into Tens and Ones
  int curSecsTens = now.second()/10;
  int curSecsOnes = now.second()%10;
  //Convert it into angles
  int curSecsTensAngle = curSecsTens * 20;
  int curSecsOnesAngle = curSecsOnes * 20;
  //Write Seconds Motors
  secondsTens.write(curSecsTensAngle);
  secondsOnes.write(curSecsOnesAngle);
  
  //Split the Minutes into Tens and Ones
  int curMinsTens = now.minute()/10;
  int curMinsOnes = now.minute()%10;
  //Convert it into angles
  int curMinsTensAngle = curMinsTens * 20;
  int curMinsOnesAngle = curMinsOnes * 20;
  //Write Minutes Motors
  minutesTens.write(curMinsTensAngle);
  minutesOnes.write(curMinsOnesAngle);

  
  //Split the hours into Tens and Ones
  int curHoursTens = now.hour()/10;
  int curHoursOnes = now.hour()%10;
  //Convert it into angles
  int curHoursTensAngle = curHoursTens * 20;
  int curHoursOnesAngle = curHoursOnes * 20;
  //Write Hours Motors
  hoursTens.write(curHoursTensAngle);
  hoursOnes.write(curHoursOnesAngle);
 
}