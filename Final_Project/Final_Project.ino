
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

  /* call a read function looking for messages
   * if we get some, store them for other funtions to use
   */
  alan.btclient.scanForMessage();

  getReactorFuelRod();

  storeFuelRod();

  getSupplyRod();

  storeSupplyRod();
}

/* here's how we want this to work:
 * ... on the first iteration, driveUntilReactorTube will execute once
   ... and all the other functions will do nothing.
   ... once driveUntilReactorTube is done, the next function
   ... will executre, ect. ect...
   ... when the last function is done, this function should do nothing
   ... to be clear, NONE OF THESE FUNCTIONS ARE BLOCKING. they all only
   ... run one iteration at a time
 */

void getReactorFuelRod(){
  alan.driveUntilReactorTube();
  alan.lowerArm();
  alan.closeGripper();
  alan.raiseArm();
}

void storeFuelRod(){
  alan.turnAround();
  alan.driveUntilLine();
  alan.driveToStorageContainer();
}

void getSupplyRod(){
}

void storeSupplyRod(){
}
