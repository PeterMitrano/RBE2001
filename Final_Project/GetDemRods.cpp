#include "GetDemRods.h"

#include "End.h"
#include "CalibrateRoutine.h"
#include "GetRodFromReactor.h"
#include "StoreRodInReactor.h"
#include "GetRodFromSupply.h"
#include "StoreRod.h"


GetDemRods::GetDemRods() : CommandGroup("get dem rods") {
  addSequential(new CalibrateRoutine());
  //first half
  addSequential(new GetRodFromReactor(1));
  addSequential(new StoreRod());
  addSequential(new GetRodFromSupply());
  addSequential(new StoreRodInReactor(1));
  //second half
}
