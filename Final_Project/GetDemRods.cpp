#include "GetDemRods.h"

#include "CalibrateRoutine.h"
#include "GetRodFromReactor.h"
#include "DriveUntilIntersection.h"
#include "DriveUntilReactorTube.h"
#include "CloseGripper.h"
#include "OpenGripper.h"

//includes for other sub commands..

GetDemRods::GetDemRods() : CommandGroup("get dem rods") {
  addSequential(new CalibrateRoutine());
  addSequential(new DriveUntilReactorTube());
  addSequential(new CloseGripper());
  addSequential(new OpenGripper());
//  addSequential(new GetRodFromReactor(1));
}
