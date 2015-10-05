#include "CommandGroup.h"

class PathPlanner {
  public:
    PathPlanner(int currentRow, int currentCol, int currentDirection, CommandGroup *path);
    void plan(int destRow, int destCol, int destDirection);
    void planToFace(int currentDirection);
  private:
    int col, row, direction;
    CommandGroup *path;
};
