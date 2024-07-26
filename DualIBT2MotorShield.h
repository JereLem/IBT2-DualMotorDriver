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
    // Pin mapping
    unsigned char _RPWM1, _LPWM1, _RPWM2, _LPWM2;

};
