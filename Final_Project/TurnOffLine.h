#pragma once
/** \brief
* turns off of the line in a direction 
*/
#include "Command.h"
#include "Robot.h"

class TurnOffLine : public Command {
  public:
  	/** \param direction specified by bluetooth, either ccw or cw
    */
    TurnOffLine(int direction);

	/** \brief
    * sets a timeout and plays a song
    */
    void initialize();

    /** \brief
    * determines the direction then turns that direction 
    */
    virtual void execute();

    /** \returns true when timeout occurs 
    */
    bool isFinished();

    /** \brief
    * stops the robot
    */
    virtual void end();
  private:

  	/** \brief
    * direction specified by bluetooth
    */
    int direction;
};
