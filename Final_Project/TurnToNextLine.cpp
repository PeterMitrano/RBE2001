#include "TurnToNextLine.h"

#include "TurnOffLine.h"
#include "TurnUntilLine.h"

TurnToNextLine::TurnToNextLine(int direction) : CommandGroup("turn around"){
  //0 represents clockwise
  //1 represent counter clockwise
  addSequential(new TurnOffLine(direction));
  addSequential(new TurnUntilLine(direction));
}

TurnToNextLine::TurnToNextLine() : TurnToNextLine(1){
}
