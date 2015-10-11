#pragma once
/** \brief
* turns until it finds the next line and updates current direction
*/
#include "CommandGroup.h"
#include "Robot.h"

class TurnToNextLine : public CommandGroup {
  public:
	/** \param direction given by bluetooth, either ccw or cw
    */
    TurnToNextLine(int direction);

    /** \brief
    * turns cw to next line
    */
    TurnToNextLine();

    /** \brief
    * updates direction 
    */
    void end();
  private:

  	/** \brief
    * direction specified by bluetooth
    */
    int direction;
};
