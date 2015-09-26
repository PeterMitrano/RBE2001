#include "BlinkLED.h"

BlinkLED::BlinkLED() : Command("blink LED"){}

void BlinkLED::initialize(){
  state = HIGH;
}

void BlinkLED::execute(){
  //getTime is in millis since start of command
  if ((getTime() / 200) % 2 == 0){
    state = HIGH;
  }
  else {
    state = LOW;
  }

  if (Robot::getInstance()->radiating){
    digitalWrite(Robot::LED_PIN1,state);
    digitalWrite(Robot::LED_PIN0,state);
  }
  else {
    digitalWrite(Robot::LED_PIN0,LOW);
    digitalWrite(Robot::LED_PIN1,LOW);
  }
}

bool BlinkLED::isFinished(){
  return false;
}

void BlinkLED::end(){
}
