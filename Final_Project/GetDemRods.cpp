#include "GetDemRods.h"

#include "GetRodFromReactor.h"

//includes for other sub commands..

GetDemRods::GetDemRods() {
  addSequential(new GetRodFromReactor());
  //addSequential(new StoreRod());
}
