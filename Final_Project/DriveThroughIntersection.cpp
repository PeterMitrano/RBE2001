#include "DriveThroughIntersection.h"

#include "DriveOverIntersection.h"
#include "DriveUntilIntersection.h"
#include "ScootPastIntersection.h"

DriveThroughIntersection::DriveThroughIntersection() : CommandGroup("drive through intersection") {
  addSequential(new DriveUntilIntersection());
  addSequential(new DriveOverIntersection());
  addSequential(new ScootPastIntersection());
} //drives over one intersecion
