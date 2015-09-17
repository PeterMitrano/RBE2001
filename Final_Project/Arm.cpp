#include "Arm.h"

void Arm::setup() {
  motor.attach(motorPin);

  gripper.setup();
}

void Arm::down() {
  int val = positionToServoValue(LOW_P);
  motor.write(val);
}


void Arm::up() {
  int val = positionToServoValue(HIGH_P);
  motor.write(val);
}

void Arm::setToTravelPosition() {
  int val = positionToServoValue(TRAVEL_P);
  motor.write(val);
}

int Arm::positionToServoValue(Position p) {
  switch (p) {
    case LOW_P:
      return 180;
    case TRAVEL_P:
      return 90;
    case HIGH_P:
      return 40;
  }
}

void Arm::openGripper() {
  gripper.opn();
}

void Arm::closeGripper() {
  gripper.cls();
}
