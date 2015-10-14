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

    /** \brief HARD is used when we close the gripper all the way.
     * This is used when we pick up tubes from supply
     */
    const static int HARD = 180;

    /** \brief SOFT is used when we close the gripper part of the way.
     * this is used when we pick up tubes from the reactor
     */
    const static int SOFT = 162;

  private:

    /** \brief force to grip with */
    int force;
};

