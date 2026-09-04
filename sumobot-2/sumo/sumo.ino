/******************************************************************************

Pin config:

Motor Driver -> Arduino Pin Number

1) PWMA -> 5 pmw
2) INA1 -> 2
3) INA2 -> 4
4) PWMB -> 6 pmw
5) INB1 -> 7
6) INB2 -> 8

IR Pins -> Arduino Pin Number

1) leftSensor -> 10
2) rightSensor -> 11

Ultrasonic -> Arduino Pin Number

1) trigPin -> 12
2) echoPin -> 13

******************************************************************************/

#include <SparkFun_TB6612.h>


// motor setup

#define AIN1 2
#define BIN1 7
#define AIN2 4
#define BIN2 8
#define PWMA 5
#define PWMB 6
#define STBY 9

const int offsetA = 1;
const int offsetB = 1;

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);


const int forwardSpeed = 255;
const int turnSpeed = 255;
const int defaultTurnSpeed = 100;
const int reverseSpeed = -255;
const int reverseDuration = 500;
const int turnDuration = 1500;

// ir setup
const int rightSensorPin = 10;
const int leftSensorPin = 11;

// ultrasonic setup
const int trigPin = 12;
const int echoPin = 13;
long duration = 0;
int distance = 0;

const int safeDistance = 15;  // if detected less than this distance, go forward; meaning enemy is infront

void setup() {
  // ir
  pinMode(rightSensorPin, INPUT);
  pinMode(leftSensorPin, INPUT);

  // ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


void loop() {
  forward(motor1, motor2, forwardSpeed);

  // ir
  int rightSensorValue = digitalRead(rightSensorPin);
  int leftSensorValue = digitalRead(leftSensorPin);

  // ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;


  // if either IR sensor detects black, border of the ring; brake!
  // reverse a little, then turn left 360 degrees
  // if any distance flactuation while turning (maybe enemy robot) then go forward
  if (rightSensorValue == 0 || leftSensorValue == 0) {
    brake(motor1, motor2);
    back(motor1, motor2, reverseSpeed);
    delay(reverseDuration);

    turnRight(motor1, motor2, turnSpeed, defaultTurnSpeed);
    delay(turnDuration);

    if (distance <= safeDistance) {
      forward(motor1, motor2, forwardSpeed);
    }
  }
}


void turnLeft(Motor motor1, Motor motor2, int turnSpeed, int defaultTurnSpeed) {
  motor1.drive(turnSpeed);
  motor2.drive(defaultTurnSpeed);
}

void turnRight(Motor motor1, Motor motor2, int turnSpeed, int defaultTurnSpeed) {
  motor1.drive(defaultTurnSpeed);
  motor2.drive(turnSpeed);
}
