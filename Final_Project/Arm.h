#pragma once
/* \brief arm class
 * functions here control the 4 bar linkage/slider crank
 */

#include <Servo.h>
#include "Gripper.h"
#include <Arduino.h>

class Arm {
  public:

    /* \brief initializes servos and other stuff. called by main arduino setup */
    void setup();

    /* \brief lower arm all the way to the top */
    void down();

    /* \brief raise arm all the way to the bottom */
    void up();

    void stop();

    void setPosition(int setpoint);

    /* \brief return position in encoder counts */
    int position();

    Gripper *gripper;

  private:

    int motorPin = 10;

    /* \brief used by PI to computer integral */
    int integral;

    /* PI constants */
    const float kP = -1;
    const float kI = -1;

    /* positions */
    const int UP_POSITION = -1;
    const int DOWN_POSITION = -1;

    Servo motor;
};
