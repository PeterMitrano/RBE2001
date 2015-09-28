#include "GetRodFromReactor.h"
#include "NavigateToReactor.h"
#include "OpenGripper.h"
#include "CloseGripper.h"
#include "LowerArm.h"
#include "RaiseArm.h"
#include "DriveUntilIntersection.h"

GetRodFromReactor::GetRodFromReactor(const int reactorNumber) : CommandGroup("get rod from reactor") {
    addSequential(new DriveUntilIntersection());

//  addSequential(new NavigateToReactor(reactorNumber));

//  addParallel(new OpenGripper());
//  addSequential(new LowerArm());
//  addSequential(new CloseGripper());
//  addSequential(new RaiseArm());
}
