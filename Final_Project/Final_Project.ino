
/* main robot class
 * controls basic routine
 */

#include "Robot.h"

Robot alan;

void setup() {
  Serial.begin(9600);
  alan.setup();
}

void loop() {

  getReactorFuelRod();

  storeFuelRod();

  getSupplyRod();

  storeSupplyRod();

}

void getReactorFuelRod(){
  alan.driveUntilReactorTube();
  alan.lowerArm();
  alan.closeGripper();
  alan.raiseArm();
}

void storeFuelRod(){
  // turn around
  alan.turnAround();
  alan.driveUntilLine();

}

void getSupplyRod(){
}

void storeSupplyRod(){
}
