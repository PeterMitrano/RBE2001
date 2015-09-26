#include "CalibrateRoutine.h"

#include "Turn.h"
#include "Calibrate.h"

CalibrateRoutine::CalibrateRoutine(): CommandGroup("calibrate routine"){
  addSequential(new Turn(1,1500));
  addSequential(new Calibrate());
  addSequential(new Turn(2,1500));
}
