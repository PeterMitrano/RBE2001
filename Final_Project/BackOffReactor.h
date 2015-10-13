#pragma once

/** \brief Backs off reactor and turns around */

#include "Robot.h"
#include "CommandGroup.h"

class BackOffReactor : public CommandGroup {
  public:
    /** \brief constructor needs to take which reactor you're going to */
    BackOffReactor(int reactorNumber);

    /** \brief sets a song to play */
    void initialize();
  private:

    /** \brief internal value of which reactor you're going to */
    int reactorNumber;
};
