#pragma once
/* arm class
 * functions here control the 4 bar linkage
 */

#include <Servo.h>
#include "Gripper.h"
#include <Arduino.h>

class Arm {
  public:

    /* initializes servos and other stuff. called by main arduino setup */
    void setup();

    /* lower arm all the way to the top */
    void down();

    /* raise arm all the way to the bottom */
    void up();

    void stop();

    void setPosition(int setpoint);

    /* return position in encoder counts */
    int position();

    Gripper *gripper;

  private:

    int motorPin = 10;

    /* used by PI to computer integral */
    int integral;

    /* PI constants */
    const float kP = -1;
    const float kI = -1;

    /* positions */
    const int UP_POSITION = -1;
    const int DOWN_POSITION = -1;

    Servo motor;
};
