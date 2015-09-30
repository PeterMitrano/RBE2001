#include "CalibrateRoutine.h"

#include "TurnUntilLine.h"
#include "Calibrate.h"
#include "CalibrateArm.h"
#include "RaiseArm.h"
#include "OpenGripper.h"

CalibrateRoutine::CalibrateRoutine(): CommandGroup("calibrate routine"){
  addParallel(new CalibrateArm());
  addSequential(new Calibrate());
  addSequential(new TurnUntilLine(2));
  addParallel(new OpenGripper());
  addSequential(new RaiseArm());
}
