#include <ServoSmooth.h>
#include <Servo.h>

ServoSmooth servoSmooth20K1;
ServoSmooth servoSmooth20K2;

Servo servo;

const int servoPin = 11;
const int servo1Pin = 9;


void moveSmoothServo(int position, int delayTime = 0) {
  servoSmooth20K1.setTargetDeg(position);
  while (!servoSmooth20K1.tick());
  Serial.println("Servo " + (String)position);
  delay(delayTime);
}

void attachServos20K1() {
  servoSmooth20K1.attach(servoPin, 400, 2400);  // Attach servo to pin 9
  servoSmooth20K1.setAutoDetach(true);
  servoSmooth20K1.setSpeed(140);  // Set speed value
  servoSmooth20K1.setAccel(0);
}

void setup() {
    Serial.begin(9600);
    attachServos20K1();
    // attachServos20K(servoSmooth20K2, servo1Pin, 80);
    // servo.attach(servo1Pin);
    // servo.write(150);
    // delay(500);
    // moveSmoothServo(0, 1000);
    // delay(500);
    // moveSmoothServo(30, 1000);
    // delay(500);
    // moveSmoothServo(90, 1000);
    // delay(500);

    moveSmoothServo(30, 3000);
    // moveSmoothServo(90, 3000);

    // moveSmoothServo(90, 3000);
    // moveSmoothServo(0, 3000);
    // moveSmoothServo(90, 3000);

    // moveSmoothServo(servoSmooth20K2, 80, 1000);
    // for (int i=0; i<160; i+=10) {
    //   moveSmoothServo(i, 1000);
    // }

}
// int i=0;
void loop() {
   //moveSmoothServo1(i, 500);
  //  moveSmoothServo1(30, 3000);

   //i+=10;
}