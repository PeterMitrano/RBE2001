#pragma once
/** \brief
* raises the arm 
*/
#include "Robot.h"
#include "Command.h"

class RaiseArm : public Command {
  public:
    RaiseArm();

    /** \brief
    * plays a song and begins bringing the arm up
    */
    void initialize();

    /** \brief
    * does nothing 
    */
    void execute();

    /** \returns true when arm is at top
    */
    bool isFinished();

    /** \brief
    * does nothing 
    */
    void end();
};
