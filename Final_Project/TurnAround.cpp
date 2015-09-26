#include "TurnAround.h"

#include "TurnOffLine.h"
#include "TurnUntilLine.h"

TurnAround::TurnAround() : CommandGroup("turn around"){
  //0 represents clockwise
  //1 represent counter clockwise
  addSequential(new TurnOffLine(1));
  addSequential(new TurnUntilLine(1));
}
