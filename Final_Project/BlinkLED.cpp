#include "BlinkLED.h"

void BlinkLED::initialize(){
  state = LOW;
}

void BlinkLED::execute(){
  //getTime is in millis since start of command
  if (getTime() % 1000 == 0){
    state = !state;
  }
  
  digitalWrite(5,state);
}

bool BlinkLED::isFinished(){
  return digitalRead(4);
}
