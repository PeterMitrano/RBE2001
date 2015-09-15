/* arm class
 * functions here control the 4 bar linkage
 */

#include <Servo.h>
#include "Gripper.h"

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

    enum Position {LOW_P, HIGH_P, TRAVEL_P};
  
    /* convert position enum to servo value. return value is from 0 to 180 */
    int positionToServoValue(Position p);
    
    int motorPin = -1;

    Gripper gripper;
    Servo motor;
};
