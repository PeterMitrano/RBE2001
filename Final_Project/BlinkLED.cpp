#include "BlinkLED.h"

BlinkLED::BlinkLED() : Command("blink LED"){}

void BlinkLED::initialize(){
  state = HIGH;
  digitalWrite(5,state);
}

void BlinkLED::execute(){
  //getTime is in millis since start of command
  if (((getTime()/1000) % 2) == 0){
    state = !state;
  }
  digitalWrite(5,state);
}

bool BlinkLED::isFinished(){
  return !digitalRead(4);
}

void BlinkLED::end(){}
