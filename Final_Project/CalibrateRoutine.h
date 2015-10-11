#pragma once
/** \brief
* opens the gripper and raises the arm, calibrates line sensor then turns until a line
*/
#include "CommandGroup.h"

class CalibrateRoutine : public CommandGroup{
  public:
    CalibrateRoutine();
};
