#include "TurnAround.h"

#include "TurnOffLine.h"
#include "TurnUntilLine.h"

TurnAround::TurnAround(int direction) : CommandGroup("turn around"){
  //0 represents clockwise
  //1 represent counter clockwise
  addSequential(new TurnOffLine(direction));
  addSequential(new TurnUntilLine(direction));
}
