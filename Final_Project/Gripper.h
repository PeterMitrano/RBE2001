#pragma once
/* gripper class
 * functions of gripper go here
 */
#include <Servo.h>

class Gripper {
  public:

    void setup();

    /** \brief close the gripper */
    void cls();

    /** \brief open the gripper */
    void opn();

    Servo motor;
    const static int motorPin = 6;
};
