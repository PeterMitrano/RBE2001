#include "GetDemRods.h"

#include "End.h"
#include "CalibrateRoutine.h"

#include "GetRodFromReactor.h"
#include "GetRodFromSupply.h"
#include "StoreRod.h"
#include "StoreRodInReactor.h"

#include "Halves.h"

GetDemRods::GetDemRods() : CommandGroup("get dem rods") {
  addSequential(new CalibrateRoutine());
  //first half
  //addSequential(new FirstHalf());
  //addSequential(new SecondHalf());
  //second half

  addSequential(new GetRodFromReactor(1));
  addSequential(new StoreRod());
  addSequential(new GetRodFromReactor(2));
  addSequential(new StoreRod());
  addSequential(new GetRodFromSupply());
  addSequential(new StoreRodInReactor(1));


  addSequential(new End());
}
