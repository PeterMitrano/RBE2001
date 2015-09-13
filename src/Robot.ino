#include <Robot.h>

Robot::setup(){
  leftWheel.attachPin(leftWheelPin);
  rightWheel.attatchPin(rightWheelPin);

  lineSensor.setup();
  arm.setup();
}

Robot::driveUntilLine(unsigned long timeout){
  bool infinite = false;
  if (timeout == 0){
    infinite = true;
  }

  unsigned long t0=millis();

  while ((!infinite && (millis()-t0 < timeout)) || !lineSensor.atIntersection()){
    follow_line();
  }
}

Robot::driveUntilLine(){
  driveUntilLine(0);
}

Robot::driveUntilReactorTube(unsigned long timeout){
  bool infinite = false;
  if (timeout == 0){
    infinite = true;
  }

  unsigned long t0=millis();
  while ((!infinite && (millis()-t0 < timeout)) || !digitalRead(reactor_tube_limit_pin)){
    follow_line();
  }
}
