#include <Arm.h>

void Arm::setup(){
  motor.attachPin(motorPin);

  gripper.setup();
}

void Arm::lower(){
  int val = positionToServoValue(Position.LOW);
  motor.set(val);
}


void Arm::raise(){
  int val = positionToServoValue(Position.HIGH);
  motor.set(val);
}

void Arm::setToTravelPosition(){
  int val = positionToServoValue(Position.TRAVEL);
  motor.set(val);
}

int positionToServoValue(Position p){
  switch(p){
    case LOW:
      return -1;
    case TRAVEL:
      return -2;
    case HIGH:
      return -3;
  }
}

void Arm::openGripper(){
  gripper.open();
}

void Arm::closeGripper(){
  gripper.close();
}
