/* gripper class
 * functions of gripper go here
 */
#include <Servo.h>

class Gripper{
  public:

    /* close the gripper */
    void close();

    /* open the gripper */
    void open();

  private:
    Servo motor;
}
