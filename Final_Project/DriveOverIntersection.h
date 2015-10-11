#pragma once
/** \brief
* drives over an intersection
*/
#include "Robot.h"
#include "Command.h"

class DriveOverIntersection : public Command {
  public:
    DriveOverIntersection();

    /** \brief
    * plays a song
    */
    void initialize();

    /** \brief
    * drives forward
    */
    void execute();

    /** \returns true if not on the intersection anymore 
    */
    bool isFinished();

    /** \brief
    * stops the robot 
    */
    void end();
};
