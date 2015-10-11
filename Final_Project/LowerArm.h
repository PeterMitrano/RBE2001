#pragma once
/** \brief
* lowers the arm
*/
#include "Robot.h"
#include "Command.h"

class LowerArm: public Command {
  public:
    LowerArm();

    /** \brief
    * begins lowering the arm and plays a song 
    */
    void initialize();

    /** \brief
    * does nothing 
    */
    void execute();

    /** \returns true when arm is at bottom position
    */
    bool isFinished();

    /** \brief
    * does nothing 
    */
    void end();
  private:
};
