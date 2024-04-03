#ifndef PanelStepper_h
#define PanelStepper_h

#include "Arduino.h"

typedef struct  {
  uint8_t nbr        :6 ;             // a pin number from 0 to 63
  uint8_t isActive   :1 ;             // true if this channel is enabled, pin not pulsed if false 
} StepperPin_t   ;  

typedef struct {
  StepperPin_t Pin;
  volatile unsigned int ticks;
} Stepper_t;


class PanelStepper {
public:
  PanelStepper();
  void mover(int motor, int motPausa, int rep, int dir);
  void mover1(int motor,int rep,int ramp,int limSupMot,int limInfMot,int dir);
   //uint8_t attach(int pin);           // pines a cuales conectarse
  //uint8_t attach(int pin, int min, int max); // as above but also sets min and max values for writes. 
 
};





#endif


