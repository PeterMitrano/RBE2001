#include "GetRodFromReactor.h"

GetRodFromReactor::GetRodFromReactor() {
  AddSequential(new DriveToReactor());

  AddParallel(new OpenGripper());
  AddSequential(new LowerArm());

  //AddSequential(new CloseGripper());
  //AddSequential(new RaiseArm());
}
