#pragma once
/** \brief
* calibrates the line sensor
*/
#include "Command.h"
#include "Robot.h"

class CalibrateLineSensor : public Command {
  public:
    CalibrateLineSensor();

    /** \brief
    * sets a timeout
    */
    void initialize();

    /** \brief
    * turns left and runs calibration program
    */
    void execute();

    /** \returns true when timeout has occured
    */
    bool isFinished();

    /** \brief
    * stops the robot
    */
    void end();
  private:

    /** \brief
    * defines how long the command runs for
    */
    const static int CALIBRATE_TIME = 3400;
};
