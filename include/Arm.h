/* arm class
 * functions here control the 4 bar linkage
 */

#include <Gripper.h>
#include <Servo.h>

class Arm {
  public:

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

    /* convert position enum to servo value */
    void positionToServoValue();

    enum Position {LOW, HIGH, TRAVEL};



    Gripper gripper;
    Servo motor;
}
