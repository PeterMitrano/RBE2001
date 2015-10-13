#include "CalibrateRoutine.h"

#include "RaiseArm.h"
#include "CalibrateLineSensor.h"
#include "PathPlanner.h"
#include "TurnUntilLine.h"
#include "OpenGripper.h"

CalibrateRoutine::CalibrateRoutine(): CommandGroup("calibrate routine"){
  addSequential(new CalibrateLineSensor());
  addParallel(new OpenGripper());
  addSequential(new RaiseArm());
  addSequential(new TurnUntilLine(PathPlanner::CW));
}
