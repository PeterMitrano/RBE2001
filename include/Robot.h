/* robot class
 *  functions here control the robot as a whole, and should be called from main.ino
 */

#include <Arm.h>
#include <LineSensor.h>
#include <Servo.h>

class Robot {
  public:

    /* setup servos and stuff. called by main setup */
    void setup();
    void drawWhip(); //call setup

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

  private:

    /* state machin functions */
    void is(State s):
    void isNot(State s);
    void isDone(State s);
    void isNotDone(State s);

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

    State state;

    Servo leftWheel;
    Servo rightWheel;
    LineSensor lineSensor;

    const static int reactor_tube_limit_pin = -1;
    Arm arm;

    const static int rotateSpeed = -1;
    const static int travelSpeed = -1;

    /* used to track calibration */
    unsigned long calibrate_time = 0;
}
