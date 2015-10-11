#pragma once
/** \brief
 * drives until it reaches the reactor tube
 */
#include "Robot.h"
#include "Command.h"

class DriveUntilReactorTube : public Command {
  public:
    DriveUntilReactorTube();

    /** \brief
    * does nothing 
    */
    void initialize();

    /** \brief
    * line follows forward 
    */
    void execute();

    /** \brief
    * returns true when the front limit switch triggers 
    */
    bool isFinished();

    /** \brief
    * stops driving and increments the position 
    */
    void end();
};
