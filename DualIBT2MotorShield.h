#pragma once

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || \
    defined(__AVR_ATmega328PB__) || defined (__AVR_ATmega32U4__)
  #define DUALIBT2MOTORSHIELD_TIMER1_AVAILABLE
#endif

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
                        unsigned char REN1,
                        unsigned char LEN1,
                        unsigned char RPWM2,
                        unsigned char LPWM2,
                        unsigned char REN2,
                        unsigned char LEN2);

    // PUBLIC METHODS
    void init(); // Initialize TIMER 1, set the PWM to 20kHZ.
    void setM1Speed(int speed); // Set speed for M1.
    void setM2Speed(int speed); // Set speed for M2.
    void setSpeeds(int m1Speed, int m2Speed); // Set speed for both M1 and M2.
    void setM1Brake(int brake); // Brake M1.
    void setM2Brake(int brake); // Brake M2.
    void setBrakes(int m1Brake, int m2Brake); // Brake both M1 and M2.

  private:
    unsigned char _RPWM1;
    unsigned char _LPWM1;
    static const unsigned char _PWM1_TIMER1_PIN = 9;
    unsigned char _REN1;
    unsigned char _LEN1;
    unsigned char _RPWM2;
    unsigned char _LPWM2;
    static const unsigned char _PWM2_TIMER1_PIN = 10;
    unsigned char _REN2;
    unsigned char _LEN2;
};
