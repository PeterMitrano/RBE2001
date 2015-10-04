#include "GetDemRods.h"

#include "CalibrateRoutine.h"
#include "GetRodFromReactor.h"
#include "OpenGripper.h"

GetDemRods::GetDemRods() : CommandGroup("get dem rods") {
  addSequential(new CalibrateRoutine());
  addSequential(new GetRodFromReactor(1));
}
