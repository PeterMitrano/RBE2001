/* arm class
 * functions here control the 4 bar linkage
 */

#include <Gripper.h>
#include <Servo.h>

class Arm {
  public:

    /* initializes servos and other stuff. called by main arduino setup */
    void setup();

    /* raise arm all the way to the top */
    void lower();

    /* lower arm all the way to the bottom */
    void raise();

    /* maybe we want a travel position */
    void setToTravelPosition();

    /* tell the gripper to open */
    void openGripper();

    /* tell the gripper to close */
    void closeGripper();

  private:

    /* convert position enum to servo value. return value is from 0 to 180 */
    int positionToServoValue(Position p);

    enum Position {LOW, HIGH, TRAVEL};

    int motorPin = -1;

    Gripper gripper;
    Servo motor;
}
