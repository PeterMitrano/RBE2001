#include "GrabRod.h"
#include "CloseGripper.h"
#include "BlinkLED.h"

GrabRod::GrabRod() : CommandGroup("grab rod") {
  addSequential(new CloseGripper());
  addSequential(new BlinkLED());
}
