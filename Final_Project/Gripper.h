#pragma once
/* gripper class
 * functions of gripper go here
 */
#include <Servo.h>

class Gripper{
  public:

    /* initializes servos and other stuff. called by main arduino setup */
    void setup();

    /* closes gripper, but returns if no rod was truly grasped */
    bool grabRod();

    /* open rod, but returns if rod was truly released */
    bool releaseRod();

    /* close the gripper */
    void cls();

    /* open the gripper */
    void opn();

    /* returns T if gripper wires don't touch, meaning the rod is present */
    bool hasRod();

  private:
    Servo motor;

    const static int motorPin = 3;
    const static int rodSensorPin = 4;
};
