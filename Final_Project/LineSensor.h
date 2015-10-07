#pragma once
/** \brief
 * functions for reading the position with respect to the line
 */

class LineSensor {
  public:

    /** \brief setup servos and stuff. called by main setup */
    void setup();

    /** \brief returns true if both sensors are on the line */
    bool atIntersection();

    /** \brief returns if line sensor is on the line */
    bool onLine();

    /** \brief returns if line sensor is off the line */
    bool offLine();

    /** \brief does raw read and storage of line sensor. This must be caled every loop
     */
    void cache();

    /** \brief get how much motor power you should adjust by. from -100 to 100 */
    int adjustmentPower();

  private:

    /** \brief holds the line position as calculated by cache. On scale of tens */
    float linePosition;
    float lastLinePosition;

    /** \brief this assumes line sensor pins are in order. This is the first (leftmost pin) */
    const static int PIN_0 = 0;

    /** \brief the board contains IR LEDs, this pin controls those LEDs */
    const static int LEDPIN = 29;

    /** \brief determines what constitutes a black line (from -100 to 100)
     * these numbers may be the same, but don't have to be
     */
    const static float OFF_POS_THRESHOLD = 1.3;
    const static float ON_POS_THRESHOLD = 0.6;

    /** PID constants for line following */
    const float kP = 8.0;
    const float kD = 1.5;
    int derivative;

    /** \brief account for broken line sensors */
    const static float COMPENSATION = 1;

    /** \brief test if we're at a line */
    const static int INTERSECTION_THRESHOLD = 2800;
    const static int LOW_SUM_THRESHOLD = 1000;
    const static int HIGH_SUM_THRESHOLD = 1600;

    /** \brief sum of raw line sensor values. used to detect intersections */
    int sum;
};
