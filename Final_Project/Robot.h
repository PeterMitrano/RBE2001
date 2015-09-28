#pragma once
/* robot class
 *  functions here control the robot as a whole, and should be called from main.ino
 */

#include "GrabRod.h"
#include <Servo.h>
#include <Arduino.h>

class Robot {
  public:

    /* single accesor */
    static Robot *getInstance();

    /* setup servos and stuff. called by main setup */
    void setup();

    void closeGripper();

  private:
    /* there's only one robot, so use private constructor */
    Robot();
    static Robot *instance;

    Servo gripperMotor;

};
