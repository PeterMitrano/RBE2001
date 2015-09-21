#include "GrabRod.h"
#include "CloseGripper.h"
#include "BlinkLED.h"

GrabRod::GrabRod(){
  addSequential(new CloseGripper());
  addSequential(new BlinkLED());
}
