#include "GetRodFromSupply.h"
#include "RaiseArm.h"
#include "NavigateToAvailableSupply.h"
#include "CloseGripper.h"
#include "OpenGripper.h"
#include "BackOffTube.h"
#include "DriveUntilReactorTube.h"

GetRodFromSupply::GetRodFromSupply() : CommandGroup("get rod from supply"){
	addSequential(new RaiseArm());
//	  addParallel(new NavigateToAvailableSupply());
  addSequential(new DriveUntilReactorTube());
	addSequential(new CloseGripper());
	addSequential(new BackOffTube(-24,-16));
	addSequential(new OpenGripper());
  addSequential(new DriveUntilReactorTube());
	addSequential(new CloseGripper());
	addSequential(new BackOffTube());
}
