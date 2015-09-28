#include "GrabRod.h"
#include "CloseGripper.h"
#include "OpenGripper.h"
#include "BlinkLED.h"

GrabRod::GrabRod() : CommandGroup("grab rod") {
  addParallel(new CloseGripper());
  addSequential(new BlinkLED());
  addParallel(new BlinkLED());
  addSequential(new OpenGripper());
  addSequential(new BlinkLED());
  addSequential(new BlinkLED());
  addSequential(new CloseGripper());
  addParallel(new BlinkLED());
  addSequential(new OpenGripper());
}
