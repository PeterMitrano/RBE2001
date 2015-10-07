#pragma once
/** \brief
 * literally just opens and closes the gripper
 */
#include <Servo.h>

class Gripper {
  public:

    /** \brief setup servo*/
    void setup();

    /** \brief close the gripper */
    void cls();

    /** \brief open the gripper */
    void opn();

  private:

    /** \brief servo object for gripper */
    Servo motor;

    /** \brief motor digital pin number */
    const static int motorPin = 6;
};
