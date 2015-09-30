
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

    /** \brief the main function for controlling the arm. All other functions should just call this */
    void control();

    /** \brief lower arm all the way to the top */
    void down();

    /** \brief raise arm all the way to the bottom */
    void up();

    void stop();

    /** \brief return true if position is within tolerance of setpoint */
    bool atPosition();

    void setPosition(long setpoint);

    /** \brief return position in encoder counts */
    int position();

    /** \brief returns true if limit switch is hit */
    bool atLim();

    /** \brief drives the arm down very slowly. used in calibrating */
    void rawDown();

    /** \brief sets encoder count to 0 */
    void resetEncoder();

    Gripper gripper;
    bool calibrated = false;

  private:

    void drive(int power);

    int motorFwdPin = 11;
    int motorRevPin = 10;

    int encAPin = 19;
    int encBPin = 20;

    int limPin = 25;

    unsigned long oldTime = 0;

    /** \brief used by PI to computer integral */
    long integral = 0;

    const long tolerance = 20;
    long lastError = 0;

    /** PI constants */
    const double kP = 0.1;
    const double kI = 0.0001;
    const double kD = 0.01;

    long setpoint = 0;

    /** positions */
    const long UP_POSITION = 6000l;
    const long DOWN_POSITION = 0l;

    Encoder encoder;
};
