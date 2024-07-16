#include "DualIBT2MotorShield.h"

// Default Constructor
DualIBT2MotorShield::DualIBT2MotorShield()
  : _RPWM1(9), _LPWM1(10), _RPWM2(5), _LPWM2(6)
{
}

// User-defined pin selection
DualIBT2MotorShield::DualIBT2MotorShield(unsigned char RPWM1, unsigned char LPWM1,
                                         unsigned char RPWM2, unsigned char LPWM2)
  : _RPWM1(RPWM1), _LPWM1(LPWM1), _RPWM2(RPWM2), _LPWM2(LPWM2)
{
}

void DualIBT2MotorShield::initTimer1For20kHz() {
  // Set Timer 1 to 20 kHz
  TCCR1A = 0;           // Clear TCCR1A register
  TCCR1B = 0;           // Clear TCCR1B register
  TCNT1  = 0;           // Clear counter value
  TCCR1B |= (1 << WGM13) | (1 << WGM12);
  TCCR1A |= (1 << WGM11) | (1 << WGM10);

  // Set non-inverting mode
  TCCR1A |= (1 << COM1A1) | (1 << COM1B1);

  // Set prescaler to 1 and start the timer
  TCCR1B |= (1 << CS10);

  // Set ICR1 register to define the top value (20 kHz)
  ICR1 = 799;  // 20 kHz
}

void DualIBT2MotorShield::initTimer2For20kHz() {
  // Set Timer 2 to ~20 kHz
  TCCR2A = 0;           // Clear TCCR2A register
  TCCR2B = 0;           // Clear TCCR2B register
  TCNT2  = 0;           // Clear counter value
  TCCR2B |= (1 << WGM22);
  TCCR2A |= (1 << WGM21) | (1 << WGM20);

  // Set non-inverting mode
  TCCR2A |= (1 << COM2A1) | (1 << COM2B1);

  // Set prescaler to 1 and start the timer
  TCCR2B |= (1 << CS20);

  // Set OCR2A register to define the top value (for ~20 kHz, use OCR2A value)
  OCR2A = 199;  // Close to 20 kHz
}

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


  // Initialize timers for 20 kHz PWM
  initTimer1For20kHz();
  initTimer2For20kHz();
}

// Set speed for Motor 1
void DualIBT2MotorShield::setM1Speed(int speed) {
  if (speed > 0) {
    analogWrite(_RPWM1, speed);
    analogWrite(_LPWM1, 0);
  } else if (speed < 0) {
    analogWrite(_RPWM1, 0);
    analogWrite(_LPWM1, -speed);
  } else {
    analogWrite(_RPWM1, 0);
    analogWrite(_LPWM1, 0);
  }
}

// Set speed for Motor 2
void DualIBT2MotorShield::setM2Speed(int speed) {
  if (speed > 0) {
    analogWrite(_RPWM2, speed);
    analogWrite(_LPWM2, 0);
  } else if (speed < 0) {
    analogWrite(_RPWM2, 0);
    analogWrite(_LPWM2, -speed);
  } else {
    analogWrite(_RPWM2, 0);
    analogWrite(_LPWM2, 0);
  }
}


// Set speed for both motors
void DualIBT2MotorShield::setSpeeds(int m1Speed, int m2Speed) {
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
}
