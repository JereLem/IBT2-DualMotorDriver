#pragma once

#include <Arduino.h>

class DualIBT2MotorShield
{
  public:
    // CONSTRUCTORS
    // Default pin selection.
    DualIBT2MotorShield();
    // User-defined pin selection.
    DualIBT2MotorShield(unsigned char RPWM1,
                        unsigned char LPWM1,
                        unsigned char RPWM2,
                        unsigned char LPWM2);

    // PUBLIC METHODS
    void init(); // Initialize the motor driver.
    void setM1Speed(int speed); // Set speed for M1.
    void setM2Speed(int speed); // Set speed for M2.
    void setSpeeds(int m1Speed, int m2Speed); // Set speed for both M1 and M2.

  private:
    unsigned char _RPWM1;
    unsigned char _LPWM1;
    static const unsigned char _PWM1_TIMER1_PIN = 9;

    unsigned char _RPWM2;
    unsigned char _LPWM2;
    static const unsigned char _PWM2_TIMER2_PIN = 10;


    void initTimer1For20kHz();
    void initTimer2For20kHz();
};
