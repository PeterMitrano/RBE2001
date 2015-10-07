
#pragma once
/** \brief functions here control the 4 bar linkage/slider crank
 */

#include <Encoder.h>
#include <Servo.h>
#include "Gripper.h"
#include <Arduino.h>

class Arm {
  public:

    Arm();

    /** \brief initializes servos and other stuff.
     *  called by main arduino setup */
    void setup();

    /** \brief the main function for controlling the arm.
     * All other functions should just call this */
    void control();

    /** \brief lower arm all the way to the top.
     * This only needs to be called once, and the arm will continue to maintain that position */
    void down();

    /** \brief raise arm all the way to the bottom.
     * This only needs to be called once, and the arm will continue to maintain that position  */
    void up();

    /** \brief cold stop the arm.
     * This is used to calibrate the arm */
    void stop();

    /** \brief return true if position is within tolerance of setpoint */
    bool atPosition();

    /** \brief return position in encoder counts */
    int position();

    /** \brief returns true if limit switch is hit */
    bool atLim();

    /** \brief drives the arm down very slowly.
     * used in calibrating */
    void rawDown();

    /** \brief sets encoder count to 0 */
    void resetEncoder();

    /** \brief gripper object is part of the arm */
    Gripper gripper;

    /** \brief flag to keep the control function from running without calibration */
    bool calibrated = false;

  private:

    /** \brief raw function for controlling */
    void drive(int power);

    Encoder encoder;

    int motorFwdPin = 10;
    int motorRevPin = 9;
    int encAPin = 19;
    int encBPin = 18;
    int limPin = 25;

    /** \brief last time in millis that the PID was run.
     * used to only update PID every CONTROL_TIME */
    unsigned long lastControlTime = 0;

    /** \brief constant in millis for how often to calculate PID */
    const unsigned long CONTROL_TIME = 50l;

    /** \brief used by PI to computer integral */
    long integral = 0;

    /** \brief last error in encoder ticks */
    long lastError = 0;

    /** \brief how many encoder ticks until we're considered at our setpoint */
    const long tolerance = 100;

    /** \brief PI constants */
    const double kP = 0.1;
    const double kI = 0.002;
    const double kD = 0.01;

    /** \brief absolute value cap of integral.
     * this protects us from <a href = "https://en.wikipedia.org/wiki/Integral_windup">integral windup</a> */
    const long MAX_INTEGRAL = 500l;

    long setpoint = 0;

    /** positions */
    const long UP_POSITION = 6200l;
    const long DOWN_POSITION = 0l;
};
