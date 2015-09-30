#pragma once
/** \brief arm class
 * functions here control the 4 bar linkage/slider crank
 */

#include <Encoder.h>
#include <Servo.h>
#include "Gripper.h"
#include <Arduino.h>

class Arm {
  public:

    Arm();

    /** \brief initializes servos and other stuff. called by main arduino setup */
    void setup();

    /** \brief lower arm all the way to the top */
    void down();

    /** \brief raise arm all the way to the bottom */
    void up();

    void stop();

    void setPosition(int setpoint);

    /** \brief return position in encoder counts */
    int position();

    /** \brief returns true if limit switch is hit */
    bool atLim();

    /** \brief drives the arm down very slowly. used in calibrating */
    void rawDown();

    /** \brief sets encoder count to 0 */
    void resetEncoder();

    Gripper gripper;

  private:

    void drive(int power);

    int motorFwdPin = 11;
    int motorRevPin = 10;

    int encAPin = 19;
    int encBPin = 20;

    int limPin = 25;

    /** \brief used by PI to computer integral */
    int integral;

    /** PI constants */
    const float kP = 0;
    const float kI = 0;

    /** positions */
    const int UP_POSITION = -1;
    const int DOWN_POSITION = -1;

    Encoder encoder;
};
