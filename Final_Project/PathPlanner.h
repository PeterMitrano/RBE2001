#include "CommandGroup.h"

/** \brief Assemble command groups to go from one location to another */
class PathPlanner {
  public:

    /** \brief Constructor. Grabs robot's current position and direction.
     * make sure you call this from the location you want to plan from */
    PathPlanner();

    /** \brief plan from the robot's current position
     * (at time of construction of the plath planner object)
     * to some other point on the field
     * Format is (row,column)
     * 0,0 is the top corner (nothing actually there)
     * 1,0 is the first reactor, (2,2) is storage tube 4, (0,4) is supply tube 1
     */
    CommandGroup *plan(int destRow, int destCol, int destDirection);

    /** \brief convenient constants for navigations */
    const static int NORTH = 0,
          EAST = 1,
          SOUTH = 2,
          WEST = 3,
          CW = 1,
          CCW = -1;

  private:

    /** \brief adds command groups to the path for turning
     * \param[_in] currentDirection the direction you're facing at this point in the plan
     */
    void planToFace(int currentDirection);

    /** \brief ints for storing current col row and direction in the plan */
    int col, row, direction;

    /** \brief CommandGroup to be assembled */
    CommandGroup *path;
};
