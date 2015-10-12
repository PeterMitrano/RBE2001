#include "Halves.h"

#include "GetRodFromReactor.h"
#include "GetRodFromSupply.h"
#include "StoreRod.h"
#include "StoreRodInReactor.h"
#include "End.h"

FirstHalf::FirstHalf() : CommandGroup("first half"){}
	/*
  addSequential(new GetRodFromSupply());
  addSequential(new StoreRodInReactor(2));
  addSequential(new GetRodFromSupply());
    */
  void FirstHalf::initialize(){

  addSequential(new GetRodFromReactor(1));
  addSequential(new StoreRod());
  addSequential(new GetRodFromSupply());
  addSequential(new StoreRodInReactor(1));
  Serial.println("==Added First Half");
}


SecondHalf::SecondHalf() : CommandGroup("second half"){}
	/*
  addSequential(new StoreRodInReactor(1));
  addSequential(new GetRodFromReactor(2));
  addSequential(new StoreRod());
    */
  void SecondHalf::initialize(){

  addSequential(new GetRodFromReactor(2));
  addSequential(new StoreRod());
  addSequential(new GetRodFromSupply());
  addSequential(new StoreRodInReactor(2));

  Serial.println("==Added Second Half");
}

