#include "DualIBT2MotorShield.h"
#include <PWM.h>

// Default Constructor
DualIBT2MotorShield::DualIBT2MotorShield()
  : _RPWM1(11), _LPWM1(10), _RPWM2(9), _LPWM2(3)
{
}

// User-defined pin selection
DualIBT2MotorShield::DualIBT2MotorShield(unsigned char RPWM1, unsigned char LPWM1,
                                         unsigned char RPWM2, unsigned char LPWM2)
  : _RPWM1(RPWM1), _LPWM1(LPWM1), _RPWM2(RPWM2), _LPWM2(LPWM2) {}


// Initialize the motor driver
void DualIBT2MotorShield::init() {

  // Initialize Motor 1 pins
  pinMode(_RPWM1, OUTPUT);
  pinMode(_LPWM1, OUTPUT);

  // Initialize Motor 2 pins
  pinMode(_RPWM2, OUTPUT);
  pinMode(_LPWM2, OUTPUT);


  // Set initial motor state to stopped
  digitalWrite(_RPWM1, LOW);
  digitalWrite(_LPWM1, LOW);
  digitalWrite(_RPWM2, LOW);
  digitalWrite(_LPWM2, LOW);
}

// Set speed for Motor 1
void DualIBT2MotorShield::setM1Speed(int speed) {
  speed = constrain(speed, -255, 255);
  if (speed > 0) {
    pwmWrite(_RPWM1, speed);
    pwmWrite(_LPWM1, 0);
  } else if (speed < 0) {
    pwmWrite(_RPWM1, 0);
    pwmWrite(_LPWM1, -speed);
  } else {
    pwmWrite(_RPWM1, 0);
    pwmWrite(_LPWM1, 0);
  }
}

// Set speed for Motor 2
void DualIBT2MotorShield::setM2Speed(int speed) {
  speed = constrain(speed, -255, 255);
  if (speed > 0) {
    pwmWrite(_RPWM2, speed);
    pwmWrite(_LPWM2, 0);
  } else if (speed < 0) {
    pwmWrite(_RPWM2, 0);
    pwmWrite(_LPWM2, -speed);
  } else {
    pwmWrite(_RPWM2, 0);
    pwmWrite(_LPWM2, 0);
  }
}


// Set speed for both motors
void DualIBT2MotorShield::setSpeeds(int m1Speed, int m2Speed) {
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
}
