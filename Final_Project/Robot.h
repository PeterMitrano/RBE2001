#pragma once
/* robot class
 *  functions here control the robot as a whole, and should be called from main.ino
 */

#include <Arduino.h>
#include <Servo.h>
#include "GetDemRods.h"
#include "Arm.h"
#include "LineSensor.h"
#include "BTClient.h"

class Robot {
  public:

    /* single accesor */
    static Robot *getInstance();

    /* setup servos and stuff. called by main setup */
    void setup();

    /* uses line sensor to follow line
     * following is done by a weighted power to each wheel
     * weight is a function of the intensity of line sensors on that side
     * low intensity -> white -> full motor power
     * high intensity -> black -> full reverse motor power
     */
    void followLine();

    /* stop driving */
    void stopDriving();

    /* checks limit switch to tell if we've reached our destination */
    bool doneTravelling();

    bool atFuelRod();

    BTClient btclient;
    Arm *arm;
    LineSensor *lineSensor;

  private:
    /* there's only one robot, so use private constructor and instance*/
    Robot();
    static Robot *instance;

    /* used by bumper switch as a panic button function */
    static void pause();

    /* fixed power rotate */
    void rotateLeft();

    /* fixed power rotate */
    void rotateRight();

    /* low level function for setting motor power
     * input is limited between -100 (full back) and 100 (full forward)
     */
    void drive(int leftPower, int rightPower);

    Servo leftWheel;
    Servo rightWheel;
    const int leftWheelPin = 9;
    const int rightWheelPin = 11;
    const int pausePin = 2;
    const int limitPin = 22;


    const int reactorTubeLimitPin = -1;
    const int rotateSpeed = -1;
    const int travelSpeed = -1;


    /* used to track calibration */
    unsigned long calibrationTime = 0;

};
