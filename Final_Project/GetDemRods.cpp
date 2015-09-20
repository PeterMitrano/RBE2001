#include "GetDemRods.h"

//includes for other sub commands..

GetDemRods::GetDemRods() {
  AddSequential(new GetRodFromReactor());
  //AddSequential(new StoreRod());
}
