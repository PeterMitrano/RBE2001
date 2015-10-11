#include "GetDemRods.h"

#include "End.h"
#include "CalibrateRoutine.h"
#include "Halves.h"

GetDemRods::GetDemRods() : CommandGroup("get dem rods") {
  addSequential(new CalibrateRoutine());
  //first half
  addSequential(new FirstHalf());
  addSequential(new SecondHalf());
  //second half
  addSequential(new End());
}
