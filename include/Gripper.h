/* gripper class
 * functions of gripper go here
 */
#include <Servo.h>

class Gripper{
  public:

    /* initializes servos and other stuff. called by main arduino setup */
    void setup();

    /* closes gripper, but returns if no rod was truly grasped */
    bool grabRod();

    /* open rod, but returns if rod was truly released */
    bool releaseRod();

    /* close the gripper */
    void close();

    /* open the gripper */
    void open();

    /* returns T if gripper wires don't touch, meaning the rod is present */
    bool hasRod();

  private:
    Servo motor;

    const static int motorPin = -1;
    const static int rodSensorPin = -1;
}
