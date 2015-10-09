#include "CommandGroup.h"

class PathPlanner {
  public:
    PathPlanner();
    CommandGroup *plan(int destRow, int destCol, int destDirection);
    void planToFace(int currentDirection);
    const static int NORTH = 0,
          EAST = 1,
          SOUTH = 2,
          WEST = 3,
          CW = 1,
          CCW = -1;
  private:
    int col, row, direction;
    CommandGroup *path;
};
