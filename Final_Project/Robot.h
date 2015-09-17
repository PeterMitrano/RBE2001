#pragma once
/* robot class
 *  functions here control the robot as a whole, and should be called from main.ino
 */

#include "Arm.h"
#include "State.h"
#include "LineSensor.h"
#include <Arduino.h>

class Robot {
  public:

    /* setup servos and stuff. called by main setup */
    void setup();

    /* print the value of Robot::state; */
    static void printState();

    /* scans back and forth to gather intensity line sensor data */
    void calibrateLineSensor();

    /* uses line sensor to follow line
     * following is done by a weighted power to each wheel
     * weight is a function of the intensity of line sensors on that side
     * low intensity -> white -> full motor power
     * high intensity -> black -> full reverse motor power
     */
    void followLine();

    /* drives until line inifitely */
    void driveUntilLine();

    /* drive until line with timeout
     * returns False if the drive timed out
     */
    bool driveUntilLine(unsigned long timeout);

    /* drive until reacetor tube inifitely */
    void driveUntilReactorTube();

    /* drive until reacetor tube with timeout
     * returns false if the drive timed out
     */
    bool driveUntilReactorTube(unsigned long timeout);

    /* checks limit switch to tell if we've reached our destination */
    bool doneTravelling();

    /* send calls to arm */
    void lowerArm();
    void raiseArm();

  private:

    /* used by bumper switch as a panic button function */
    static void pause();

    /* state machine functions */
    bool is(State s);
    bool isNot(State s);
    bool isDone(State s);
    bool isNotDone(State s);

    /* actual states */
    static State SETUP,
           CALIBRATING,
           PAUSED;

    /* rotate right at fixed power until right line sensor detects line */
    void rotateRightUntilLine();

    /* same as rotate right */
    void rotateLeftUntilLine();

    /* fixed power rotate */
    void rotateLeft();

    /* fixed power rotate */
    void rotateRight();

    /* low level function for setting motor power
     * input is limited between -100 (full back) and 100 (full forward)
     */
    void drive(int leftPower, int rightPower);

    /* the overall procedure of the robot is a simple state machine
     * all states are listed here, and handled as a switch/case statement in the src
     */

    static State state;

    Servo leftWheel;
    Servo rightWheel;
    const int leftWheelPin = 9;
    const int rightWheelPin = 11;
    const int pausePin = 2;
    const int limitPin = 22;

    LineSensor lineSensor;
    Arm arm;

    const int reactor_tube_limit_pin = -1;
    const int rotateSpeed = -1;
    const int travelSpeed = -1;

    /* used to track calibration */
    unsigned long calibrationTime = 0;
};
