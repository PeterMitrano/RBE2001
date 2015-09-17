
/* main robot class
 * controls basic routine
 */

#include "Servo.h"
#include "Robot.h"

Robot alan;

void setup() {
  Serial.begin(9600);
  alan.setup();
}

void loop() {
  alan.printState();
  Serial.println(alan.doneTravelling());

  alan.drive(0,0);
}
