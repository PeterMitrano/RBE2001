#pragma once
/** /brief 
* backs off of the tube
*/ 
#include "Robot.h"
#include "Command.h"

class BackOffTube : public Command {
  public:
    BackOffTube();

    /** \brief
    * backs up with set motor speeds
    *   \param leftspeed is left motor speed
    *   \param rightspeed is right motor speed
    */
    BackOffTube(int leftSpeed, int rightSpeed);

    /** \brief
    * sets a timeout for the time that the robot backs up
    */
    void initialize();

    /** \brief
    * the robot backs up using the parameters it is given
    */
    void execute();

    /** \returns true if timeout has occured
    */
    bool isFinished();

    /** \brief
    * stops the robot
    */
    void end();
  private:
    /** \brief
    * variables used for the command 
    */
    int rPower,lPower;

    /** \brief
    * the time the robot drives back for 
    */
    const int backOffTime = 650;
};
