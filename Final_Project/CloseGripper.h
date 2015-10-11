#pragma once
/** \brief
* closes the gripper
*/
#include "Robot.h"
#include "Command.h"

class CloseGripper: public Command {
  public:
    CloseGripper(int force);
    CloseGripper();

    /** \brief
    * sets a timeout and begins closing the gripper
    */
    void initialize();

    /** \brief
    * does nothing 
    */
    void execute();

    /** \returns true when timeout has occured
    */
    bool isFinished();

    /** \brief
    * does nothing 
    */
    void end();
    const static int HARD = 180,
          SOFT = 165;
  private:
    int force;
};

