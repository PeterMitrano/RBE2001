#include "GetDemRods.h"

#include "End.h"
#include "CalibrateRoutine.h"
#include "GetRodFromReactor.h"
#include "StoreRod.h"
#include "GetRodFromSupply.h"
#include "StoreRodInReactor.h"

GetDemRods::GetDemRods() : CommandGroup("get dem rods") {
  addSequential(new CalibrateRoutine());
  addSequential( new GetRodFromReactor(1));
  addSequential( new StoreRod());
  addSequential( new GetRodFromSupply());
  addSequential( new StoreRodInReactor(1));
  addSequential( new GetRodFromReactor(2));
  addSequential( new StoreRod());
  addSequential( new GetRodFromSupply());
  addSequential( new StoreRodInReactor(2));
  addSequential(new End());
}
