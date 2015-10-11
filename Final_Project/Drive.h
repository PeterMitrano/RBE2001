#pragma once
/** \brief
* drives forward forever 
*/
#include "Robot.h"
#include "Command.h"

class Drive : public Command{
  public:
    Drive();

    /** \brief
    * does nothing
    */
    void initialize();

    /** \brief
    * drives forward
    */
    void execute();

    /** \returns false 
    */
    bool isFinished();

    /** \brief
    * does nothing 
    */
    void end();
};
