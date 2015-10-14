#pragma once
/** \brief functions here control the 4 bar linkage/slider crank
 */

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

    /** \brief return position from 0 to 1024 */
    int position();

    /** \brief gripper object is part of the arm */
    Gripper gripper;

  private:

    /** \brief raw function for controlling */
    void drive(int power);

    /** pin numbers */
    int potPin = 9,
        motorFwdPin = 10,
        motorRevPin = 9;

    /** \brief last time in millis that the PID was run.
     * used to only update PID every CONTROL_TIME */
    unsigned long lastControlTime = 0;

    /** \brief used by PID to computer derivative */
    long derivative = 0;

    /** \brief used by PID to computer integral */
    long integral = 0;

    /** \brief last error in encoder ticks */
    long lastError = 0;

    /** \brief setpoint for the arm. Command to control the arm set this indirectly */
    long setpoint = 0;

    /** \brief constant in millis for how often to calculate PID */
    const unsigned long CONTROL_TIME = 50l;

    /** \brief how many encoder ticks until we're considered at our setpoint */
    const long TOLERANCE = 12;

    /** \brief PI constants */
    const double kP = 0.65;
    const double kI = 0.04;
    const double kD = 0.07;

    /** \brief absolute value cap of integral.
     * this protects us from <a href = "https://en.wikipedia.org/wiki/Integral_windup">integral windup</a> */
    const long MAX_INTEGRAL = 500l;

    /** positions */
    const long UP_POSITION = 800l;
    const long DOWN_POSITION = 154l;
};
