#include "HardwareSerial.h"
#include "Arduino.h"
#include"SSM_Stepper.h"
SSM_Stepper::SSM_Stepper(uint8_t STEPPER_PIN_1,uint8_t STEPPER_PIN_2,uint8_t STEPPER_PIN_3,uint8_t STEPPER_PIN_4)
{ this-> _STEPPER_PIN_1=STEPPER_PIN_1;
  this-> _STEPPER_PIN_2=STEPPER_PIN_2;
  this-> _STEPPER_PIN_3=STEPPER_PIN_3;
  this-> _STEPPER_PIN_4=STEPPER_PIN_4;
  pinMode(_STEPPER_PIN_1, OUTPUT);
  pinMode(_STEPPER_PIN_2, OUTPUT);
  pinMode(_STEPPER_PIN_3, OUTPUT);
  pinMode(_STEPPER_PIN_4, OUTPUT);
  Stepper_init();
  Cnt_Patt=1;
}
void SSM_Stepper::Stepper_init()
{
  this->Cnt_Patt=1;
}
void SSM_Stepper::runStepper(int steps, bool dir, int time){
this->steps=steps;
this->dir=dir;
this->time=time;

  if (dir){
   for (int k=0;k<steps;k++){
     Cnt_Patt=(Cnt_Patt<<1);
     if (Cnt_Patt==16) Cnt_Patt=1;
     digitalWrite(_STEPPER_PIN_1, (Cnt_Patt==1));
     digitalWrite(_STEPPER_PIN_2, (Cnt_Patt==2));
     digitalWrite(_STEPPER_PIN_3, (Cnt_Patt==4));
     digitalWrite(_STEPPER_PIN_4, (Cnt_Patt==8));
     delay(time);
   }
  }
  else {
     for (int k=0;k<steps;k++){
     Cnt_Patt=(Cnt_Patt>>1);
     if (Cnt_Patt==0) Cnt_Patt=8;
     digitalWrite(_STEPPER_PIN_1, (Cnt_Patt==1));
     digitalWrite(_STEPPER_PIN_2, (Cnt_Patt==2));
     digitalWrite(_STEPPER_PIN_3, (Cnt_Patt==4));
     digitalWrite(_STEPPER_PIN_4, (Cnt_Patt==8));
     delay(time);
   }
  }
     digitalWrite(_STEPPER_PIN_1, LOW);
     digitalWrite(_STEPPER_PIN_2,LOW);
     digitalWrite(_STEPPER_PIN_3,LOW);
     digitalWrite(_STEPPER_PIN_4,LOW);

}
int SSM_Stepper::get_cntPtn(){
  return (this->Cnt_Patt);
}