#pragma once
/** \brief
 *  functions here control the robot as a whole.
 *  leds, bluetooth, arm, and line sensor, and music are immediate components.
 *  */

#include <Arduino.h>
#include <Servo.h>
#include <TimerOne.h>
#include <TimerThree.h>
#include <LiquidCrystal.h>
#include "GetDemRods.h"
#include "Arm.h"
#include "LineSensor.h"
#include "BTClient.h"

class Robot {
  public:

    /** \brief lsingle accesor */
    static Robot *getInstance();

    /** \brief lsetup servos and stuff. called by main setup */
    void setup();

    /** \brief inidicate radiation by blinking LEDs every 1/5th of a second */
    void blinkLEDs();

    /** \brief sends correct int over i2c to slave to play song.
     * Simple protocol is used to encode song data.
     * If the first bit is 1, the song will repeat.
     * All other bits are for the song number*/
    void setSong(int trackNumber, bool repeat);

    /** \brief sends the encoded data over i2c to the slave */
    void playSong();

    /** \brief sends correct int over i2c to slave to plause song */
    void pauseSong();

    /** \brief uses line sensor to follow line
     * following is done by a weighted power to each wheel
     * weight is a function of the intensity of line sensors on that side
     * low intensity -> white -> full motor power
     * high intensity -> black -> full reverse motor power
     */
    void followLine();

    /** \brief blindly back up */
    void backUp(int lPower, int rPower);

    /** \brief stop driving */
    void stopDriving();

    /** \brief forward drive no line track*/
    void driveFwd();

    /** \brief backward drive*/
    void driveBwd();

    /** \brief fixed power rotate */
    void rotateCW();

    /** \brief fixed power rotate */
    void rotateCCW();

    /** \brief check is we've hit a reactor tube
     * \return true when limit switch is hit */
    bool atReactorTube();

    /** \brief sets all timer flags to false */
    void resetTimerFlags();

    /** \brief print to 0,0 on lcd */
    void debugPrint(char *str);
    void debugPrint(int i);
    void debugPrint2(char *str);
    void debugPrint2(int i);

    /** \brief returns the time while not paused. used by commands that run based on time */
    static unsigned long getTime();

    /** \brief increment time counter */
    static void incrementTime();

    /** \brief used to store position
     * updated by navigate commands
     * should only be checked when the robot is done moving
     * direction is as follow: N=0, E=1, S=2, W=3
     */
    int row,col,direction;

    /** \brief the object for reading and sending bluetooth message */
    BTClient btClient;

    /** \brief the object for controling the arm */
    Arm arm;

    /** \brief the object for tracking position over the lines */
    LineSensor lineSensor;

    /** \brief lcd to debug */
    LiquidCrystal lcd;

    /** \brief set by bluetooth if resume/stop message is recieve
     * all drive motor commands depend on it being true
     */
    static bool paused;

    /** \brief flag for blinking LEDs based on radiaiton
     * to turn off LEDs, set this to false
     */
    bool radiating = false;
    bool highRadiating = false;


    static const int CALIBRATE_TIME = 3000;

  private:

    /** \brief there's only one robot, so use private constructor and instance*/
    Robot();
    static Robot *instance;


    /** \brief lused by bumper switch as a panic button function */
    static void pause();

    /** \brief low level function for setting motor power
     * input is limited between -100 (full back) and 100 (full forward)
     */
    void drive(int leftPower, int rightPower);

    /** \brief drive wheels */
    Servo leftWheel,rightWheel;

    /** \brief interrupt changes state of LED blink and send i2c */
    static void blinkAndSendInterrupt();

    /** \brief controls state of led when radiating */
    int ledState;

    /** \brief set by led timer interrupt */
    static bool timeToBlinkAndSend;

    /** \brief the encoded data to send over i2C */
    int songData;

    /** \breif led pins and stuff*/
    static const int LED_PIN0 = 22,
                 LED_PIN1 = 23,
                 BLINK_AND_SEND_PERIOD = 50; // in ms

    /*can't figure out how to make these private and still have attach work */
    static const int leftWheelPin = 5;
    static const int rightWheelPin = 4;

    const int reactorTubeLimitPin = 28;
    const int rotateSpeedForward = 34;
    const int rotateSpeedBackward = -32;
    const int travelSpeed = 30;

    static volatile unsigned long notPausedTime;
};
