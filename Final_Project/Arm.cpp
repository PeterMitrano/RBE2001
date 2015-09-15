#include "Arm.h"

void Arm::setup(){
  motor.attach(motorPin);

  gripper.setup();
}

void Arm::lower(){
  int val = positionToServoValue(LOW_P);
  motor.write(val);
}


void Arm::raise(){
  int val = positionToServoValue(HIGH_P);
  motor.write(val);
}

void Arm::setToTravelPosition(){
  int val = positionToServoValue(TRAVEL_P);
  motor.write(val);
}

int Arm::positionToServoValue(Position p){
  switch(p){
    case LOW_P:
      return -1;
    case TRAVEL_P:
      return -2;
    case HIGH_P:
      return -3;
  }
}

void Arm::openGripper(){
  gripper.opn();
}

void Arm::closeGripper(){
  gripper.cls();
}
