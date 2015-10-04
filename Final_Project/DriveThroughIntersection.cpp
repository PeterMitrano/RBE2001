#include "DriveThroughIntersection.h"

#include "DriveOverIntersection.h"
#include "DriveUntilIntersection.h"

DriveThroughIntersection::DriveThroughIntersection() : CommandGroup("get dem rods") {
  addSequential(new DriveUntilIntersection());
  addSequential(new DriveOverIntersection());
} //drives over one intersecion
