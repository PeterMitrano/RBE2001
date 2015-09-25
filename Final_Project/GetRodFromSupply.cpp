#include "GetRodFromSupply.h"
#include "RaiseArm.h"
#include "NavigateToAvailableSupply.h"
#include "CloseGripper.h"
#include "BackOffTube.h"

GetRodFromSupply::GetRodFromSupply() : CommandGroup("get rod from supply"){
	addSequential(new RaiseArm());
	  addParallel(new NavigateToAvailableSupply());
	addSequential(new CloseGripper());
	addSequential(new BackOffTube());
}
