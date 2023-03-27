#include <PID_v1.h>

#define frontSensor A0
#define rightSensor A1

#define leftMotorPWM 5
#define leftMotorDirection 4
#define rightMotorPWM 6
#define rigthMotorDirection 9
#define maxPWM 165 // voltage limit of 5V
#define Buzzer 10

#define distanceToWall 400
#define desiredDistanceFromWall 450
#define turnTime 552 // time in miliseconds that takes robot 
                    //  to make a turn of 90degrees with 30% speed 

// PID variables
double Setpoint, Input, Output, Kp, Ki, Kd;  
int frontSensorOutput, rigthSensorOutput, regulation;
PID PIDRegulation(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);


void setup() {
  // bridge H
  pinMode(leftMotorPWM, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotorDirection, OUTPUT);
  pinMode(rigthMotorDirection, OUTPUT);

  pinMode(Buzzer, OUTPUT);
  digitalWrite(Buzzer, 0);

  //regulator PID
  Setpoint = desiredDistanceFromWall;
  PIDRegulation.SetMode(AUTOMATIC);
  PIDRegulation.SetControllerDirection(REVERSE);
  PIDRegulation.SetTunings(1, 1.1, 0.3); // set with try-error method
}

void loop() {
  delay(3000); // delay on startup so robot won't run on your hands
  Main:
  frontSensorOutput = analogRead(frontSensor);
  rigthSensorOutput = analogRead(rightSensor);
 
  if (rigthSensorOutput > distanceToWall && frontSensorOutput > distanceToWall) {
    turnLeft();
    goto Main;
    }
// following right wall
  Input = rigthSensorOutput; // passing sensor output to PID regulator
  PIDRegulation.Compute();
  regulation = map(Output, 0, 255, 10, 55); 
  leftMotor(40);
  rightMotor(regulation);
  goto Main;
}

void leftMotor(int V) {
  if (V > 0) { 
    V = map(V, 0, 100, 0, maxPWM); // scalling input speed(0-100%) to motor's PWM range 
    digitalWrite(leftMotorDirection, 0); // 0 for forward, 1 for backward
    analogWrite(leftMotorPWM, V); 
  } 
  else {
    V = abs(V); 
    V = map(V, 0, 100, 0, maxPWM);
    digitalWrite(leftMotorDirection, 1); 
    analogWrite(leftMotorPWM, V); 
  }
}

void rightMotor(int V) {
  if (V > 0) { 
    V = map(V, 0, 100, 0, maxPWM);
    digitalWrite(rigthMotorDirection, 0);
    analogWrite(rightMotorPWM, V);
    } 
  else {
    V = abs(V); 
    V = map(V, 0, 100, 0, maxPWM);
    digitalWrite(rigthMotorDirection, 1); 
    analogWrite(rightMotorPWM, V);   
    }
}

void turnLeft() {
  leftMotor(-30);
  rightMotor(30);
  delay (turnTime);
}
