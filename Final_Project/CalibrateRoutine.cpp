#include "CalibrateRoutine.h"

#include "RaiseArm.h"
#include "CalibrateLineSensor.h"
#include "PathPlanner.h"
#include "TurnUntilLine.h"
#include "OpenGripper.h"

CalibrateRoutine::CalibrateRoutine(): CommandGroup("calibrate routine"){
  addParallel(new OpenGripper());
  addParallel(new RaiseArm());
  addSequential(new CalibrateLineSensor());
  addSequential(new TurnUntilLine(PathPlanner::CW));
}
