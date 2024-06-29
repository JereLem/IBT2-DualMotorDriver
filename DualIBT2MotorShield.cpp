#include "DualIBT2MotorShield.h"

DualIBT2MotorShield::DualIBT2MotorShield()
{
  // Pin map for IBT-2 motor driver
  _RPWM1 = 9;
  _LPWM1 = 10;
  _REN1 = 8;
  _LEN1 = 7;
  _RPWM2 = 5;
  _LPWM2 = 6;
  _REN2 = 4;
  _LEN2 = 3;
}

void DualIBT2MotorShield::init()
{
  // Define pinMode for the pins and set the frequency for timer1 and timer0.
  pinMode(_RPWM1, OUTPUT);
  pinMode(_LPWM1, OUTPUT);
  pinMode(_REN1, OUTPUT);
  pinMode(_LEN1, OUTPUT);
  pinMode(_RPWM2, OUTPUT);
  pinMode(_LPWM2, OUTPUT);
  pinMode(_REN2, OUTPUT);
  pinMode(_LEN2, OUTPUT);
  
  digitalWrite(_REN1, HIGH);
  digitalWrite(_LEN1, HIGH);
  digitalWrite(_REN2, HIGH);
  digitalWrite(_LEN2, HIGH);

  // Timer1 configuration for 20kHz PWM on pins 9 and 10
  TCCR1A = (1 << WGM11) | (1 << WGM10) | (1 << COM1A1) | (1 << COM1B1);
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS10);
  ICR1 = 400;

  // Timer0 configuration for 20kHz PWM on pins 5 and 6
  TCCR0A = (1 << WGM01) | (1 << WGM00) | (1 << COM0A1) | (1 << COM0B1);
  TCCR0B = (1 << CS00);
  OCR0A = 199;
}

void DualIBT2MotorShield::setM1Speed(int speed)
{
  unsigned char reverse = 0;
  if (speed < 0)
  {
    speed = -speed;
    reverse = 1;
  }
  if (speed > 400)
    speed = 400;

  // Handle the case where the PWM pins are on Timer1
  if (_RPWM1 == 9 || _LPWM1 == 10)
  {
    OCR1A = speed;
    OCR1B = 0;
  }
  else
  {
    analogWrite(_RPWM1, speed);
    analogWrite(_LPWM1, 0);
  }

  if (reverse)
  {
    digitalWrite(_RPWM1, LOW);
    digitalWrite(_LPWM1, HIGH);
  }
  else
  {
    digitalWrite(_RPWM1, HIGH);
    digitalWrite(_LPWM1, LOW);
  }
}

void DualIBT2MotorShield::setM2Speed(int speed)
{
  unsigned char reverse = 0;
  if (speed < 0)
  {
    speed = -speed;
    reverse = 1;
  }
  if (speed > 400)
    speed = 400;

  // Handle the case where the PWM pins are on Timer0
  if (_RPWM2 == 5 || _LPWM2 == 6)
  {
    OCR0A = speed;
    OCR0B = 0;
  }
  else
  {
    analogWrite(_RPWM2, speed);
    analogWrite(_LPWM2, 0);
  }

  if (reverse)
  {
    digitalWrite(_RPWM2, LOW);
    digitalWrite(_LPWM2, HIGH);
  }
  else
  {
    digitalWrite(_RPWM2, HIGH);
    digitalWrite(_LPWM2, LOW);
  }
}

void DualIBT2MotorShield::setSpeeds(int m1Speed, int m2Speed)
{
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
}

void DualIBT2MotorShield::setM1Brake(int brake)
{
  analogWrite(_RPWM1, 0);
  analogWrite(_LPWM1, 0);
}

void DualIBT2MotorShield::setM2Brake(int brake)
{
  analogWrite(_RPWM2, 0);
  analogWrite(_LPWM2, 0);
}

void DualIBT2MotorShield::setBrakes(int m1Brake, int m2Brake)
{
  setM1Brake(m1Brake);
  setM2Brake(m2Brake);
}

