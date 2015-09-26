#include "GetDemRods.h"

#include "CalibrateRoutine.h"
#include "GetRodFromReactor.h"
#include "DriveUntilIntersection.h"

//includes for other sub commands..

GetDemRods::GetDemRods() : CommandGroup("get dem rods") {
  addSequential(new CalibrateRoutine());
  addSequential(new GetRodFromReactor(1));
}
