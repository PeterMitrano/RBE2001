#pragma once
/* robot class
 *  functions here control the robot as a whole, and should be called from main.ino
 */

#include <Arduino.h>
#include <Servo.h>
#include <TimerOne.h>
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

    /** \brief sends correct int over i2c to slave to play song */
    void setSong(int trackNumber, bool repeat);

    void playSong();

    /** \brief sends correct int over i2c to slave to plause song */
    void pauseSong();

    /* uses line sensor to follow line
     * following is done by a weighted power to each wheel
     * weight is a function of the intensity of line sensors on that side
     * low intensity -> white -> full motor power
     * high intensity -> black -> full reverse motor power
     */
    void followLine();

    /** \brief blindly back up */
    void backUp();

    /* stop driving */
    void stopDriving();

    /** \brief fwd drive no line track*/
    void driveFwd();

    /* fixed power rotate */
    void rotateLeft();

    /* fixed power rotate */
    void rotateRight();

    bool atReactorTube();

    /** \brief sets all timer flags to false */
    void resetTimerFlags();

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

    int songData;

    static const int CALIBRATE_TIME = 3000;

  private:
    Servo leftWheel,rightWheel;

    /** \brief there's only one robot, so use private constructor and instance*/
    Robot();
    static Robot *instance;


    /* used by bumper switch as a panic button function */
    static void pause();

    /* low level function for setting motor power
     * input is limited between -100 (full back) and 100 (full forward)
     */
    void drive(int leftPower, int rightPower);

    /** \brief controls state of led when radiating */
    int ledState;

    /** \brief interrupt changes state of LED blink and send i2c */
    static void blinkAndSendInterrupt();

    /** \brief set by led timer interrupt */
    static bool timeToBlinkAndSend;

    /** \breif led pins and stuff*/
    static const int LED_PIN0 = 22,
                 LED_PIN1 = 23,
                 BLINK_AND_SEND_PERIOD = 100; // in ms

    /*can't figure out how to make these private and still have attach work */
    static const int leftWheelPin = 5;
    static const int rightWheelPin = 4;

    const int backupLeftSpeed = -38;
    const int backupRightSpeed= -30;
    const int pausePin = 27;
    const int reactorTubeLimitPin = 28;
    const int rotateSpeed = 30;
    const int travelSpeed = 26;
};
