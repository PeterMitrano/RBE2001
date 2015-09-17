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

    /* raise arm all the way to the top */
    void down();

    /* lower arm all the way to the bottom */
    void up();

    /* maybe we want a travel position */
    void setToTravelPosition();

    /* tell the gripper to open */
    void openGripper();

    /* tell the gripper to close */
    void closeGripper();

  private:

    enum Position {LOW_P, HIGH_P, TRAVEL_P};

    /* convert position enum to servo value. return value is from 0 to 180 */
    int positionToServoValue(Position p);

    int motorPin = 10;

    Gripper gripper;
    Servo motor;
};
