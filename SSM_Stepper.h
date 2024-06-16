#include <stdint.h>
#ifndef SSM_Stepper_h
#define SSM_Stepper_h
#include "Arduino.h"
class SSM_Stepper{
  public:
  SSM_Stepper(uint8_t STEPPER_PIN_1,uint8_t STEPPER_PIN_2,uint8_t STEPPER_PIN_3,uint8_t STEPPER_PIN_4);
  int Cnt_Patt=1;
  void Stepper_init();
  void runStepper(int steps,bool dir, int time);
  int get_cntPtn();
  private:
  uint8_t _STEPPER_PIN_1;
  uint8_t _STEPPER_PIN_2;
  uint8_t _STEPPER_PIN_3;
  uint8_t _STEPPER_PIN_4;
  int steps;
  bool dir;
  int time;

};
#endif