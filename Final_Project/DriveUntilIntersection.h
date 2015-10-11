#pragma once
/** \brief
* drives until there is an intersection
*/
#include "Robot.h"
#include "Command.h"

class DriveUntilIntersection: public Command {
  public:
    DriveUntilIntersection();

    /** \brief
    * plays a song
    */
    void initialize();

    /** \brief
    * line follows forward
    */
    void execute();

    /** \returns true when line sensor detects an intersection 
    */
    bool isFinished();

    /** \brief
    * stops driving 
    */
    void end();
};
