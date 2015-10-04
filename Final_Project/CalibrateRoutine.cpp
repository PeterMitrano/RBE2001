#include "CalibrateRoutine.h"

#include "CalibrateArm.h"
#include "RaiseArm.h"
#include "OpenGripper.h"

CalibrateRoutine::CalibrateRoutine(): CommandGroup("calibrate routine"){
//  addParallel(new CalibrateArm());
  addParallel(new OpenGripper());
//  addSequential(new RaiseArm());
}
