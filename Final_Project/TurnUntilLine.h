#pragma once
/** \brief
* turns until it hits a line
*/
#include "Command.h"
#include "Robot.h"

class TurnUntilLine : public Command {
  public:
  	/** \brief
  	* turns until the line sensor is on line
  	*/
    TurnUntilLine(int direction);

    /** \brief
    * plays a song
    */
    void initialize();

    /** \brief
    * rotates either ccw or cw
    */
    void execute();

    /** \returns
    * true if robot is on line
    */
    bool isFinished();

    /** \briefgitlgit
    * stops robot
    */
    void end();
  private:
  	/** \brief
    * this is the direction used to determine turn direction
    */
    int direction;
};
