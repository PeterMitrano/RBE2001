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

    /** \brief inidicate radiation by blinking LEDs every 1/5th of a second */
    void blinkLEDs();

    /* uses line sensor to follow line
     * following is done by a weighted power to each wheel
     * weight is a function of the intensity of line sensors on that side
     * low intensity -> white -> full motor power
     * high intensity -> black -> full reverse motor power
     */
    void followLine();

    /* stop driving */
    void stopDriving();

    /** \brief fwd drive no line track*/
    void driveFwd();

    /* fixed power rotate */
    void rotateLeft();

    /* fixed power rotate */
    void rotateRight();

    bool atReactorTube();

    /* used to store position
     * updated by navigate commands
     * should only be checked when the robot is done moving
     * direction is as follow: N=0, E=1, S=2, W=3
     */
    int row,col,direction;

    BTClient btClient;
    Arm arm;
    LineSensor lineSensor;

    /* set by bluetooth if resume/stop message is recieve
     * all drive motor commands depend on it being true
     */
    bool paused;

    /* flag for blinking LEDs based on radiaiton
     * to turn off LEDs, set this to false
     */
    bool radiating = false;

    static const int CALIBRATE_TIME = 2000;

  private:
    Servo leftWheel,rightWheel;

    /* there's only one robot, so use private constructor and instance*/
    Robot();
    static Robot *instance;

    /* used by bumper switch as a panic button function */
    static void pause();

    /* low level function for setting motor power
     * input is limited between -100 (full back) and 100 (full forward)
     */
    void drive(int leftPower, int rightPower);

    bool ledState;

    /* moar pins */
    static const int LED_PIN0 = 22,
                 LED_PIN1 = 23;

    /*can't figure out how to make these private and still have attach work */
    static const int leftWheelPin = 5;
    static const int rightWheelPin = 4;

    const int pausePin = 27;
    const int reactorTubeLimitPin = 28;
    const int rotateSpeed = 42;
    const int travelSpeed = 50;
};
