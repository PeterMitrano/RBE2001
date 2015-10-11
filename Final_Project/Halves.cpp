#include "Halves.h"

#include "GetRodFromReactor.h"
#include "GetRodFromSupply.h"
#include "StoreRod.h"
#include "StoreRodInReactor.h"
#include "End.h"

FirstHalf::FirstHalf() : CommandGroup("first half"){
  addSequential(new GetRodFromSupply());
  addSequential(new StoreRodInReactor(2));
  addSequential(new GetRodFromSupply());
}

SecondHalf::SecondHalf() : CommandGroup("second half"){
  addSequential(new StoreRodInReactor(1));
  addSequential(new GetRodFromReactor(2));
  addSequential(new StoreRod());
}
