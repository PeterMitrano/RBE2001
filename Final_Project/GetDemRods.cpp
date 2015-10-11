#include "GetDemRods.h"

#include "End.h"
#include "CalibrateRoutine.h"
#include "GetRodFromReactor.h"
#include "StoreRodInReactor.h"
#include "OpenGripper.h"
#include "GetRodFromSupply.h"
#include "StoreRod.h"

#include "DriveThroughIntersection.h"
#include "TurnToNextLine.h"

GetDemRods::GetDemRods() : CommandGroup("get dem rods") {
  
  addSequential(new CalibrateRoutine());
  addSequential(new GetRodFromReactor(1));
  addSequential(new StoreRod());
  addSequential(new GetRodFromSupply());
  //addSequential(new StoreRodInReactor(1));
  //addSequential(new OpenGripper());
  /*
  addSequential(new CalibrateRoutine());
  addSequential(new DriveThroughIntersection());
  addSequential(new TurnToNextLine());
  */
  addSequential(new End());

}
