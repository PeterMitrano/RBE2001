#include "CommandGroup.h"

class PathPlanner {
  public:
    static void plan(int currentRow, int currentCol, int destDirection, int destRow, int destCol, CommandGroup *path);
};
