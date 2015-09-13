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

    /* uses line sensor to follow line */
    void follow_line();

    /* drives until line inifitely */
    void driveUntilLine();

    /* drive until line with timeout */
    int driveUntilLine(unsigned long timeout);

    /* drive until reacetor tube inifitely */
    void driveUntilReactorTube();

    /* drive until reacetor tube with timeout */
    void driveUntilReactorTube(unsigned long timeout);

  private:

    /* the overall procedure of the robot is a simple state machine
     * all states are listed here, and handled as a switch/case statement in the src
     */
    enum STATE = {INIT, FROM_REACTOR, TO_REACTOR, FROM_STORAGE, TO_STORAGE, RETRIEVING, STORING, PAUSED};

    Servo leftWheel;
    Servo rightWheel;
    LineSensor lineSensor;

    reactor_tube_limit_pin = -1;
    Arm arm;
}
