#include "GetDemRods.h"

#include "GetRodFromReactor.h"

//includes for other sub commands..

GetDemRods::GetDemRods() : CommandGroup("get dem rods") {
  addSequential(new GetRodFromReactor());
  //addSequential(new StoreRod());
}
