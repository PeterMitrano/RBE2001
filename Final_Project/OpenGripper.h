#pragma once
/** \brief
* opens the gripper
*/
#include "Robot.h"
#include "Command.h"

class OpenGripper: public Command {
  public:
    OpenGripper();

    /** \brief
    * sets a timeout and begins opening the gripper
    */
    void initialize();

    /** \brief
    * does nothing 
    */
    void execute();

    /** \returns true when timeout occurs 
    */
    bool isFinished();

    /** \brief
    * does nothing 
    */
    void end();
};

