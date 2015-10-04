#pragma once
/** line sensor class
 * functions for reading the line sensor go here
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

    /** \brief holds the line position as calculated by cache. On scale of tens */
    float linePosition;

  private:

    /** this assumes line sensor pins are in order. This is the first (leftmost pin) */
    const static int PIN_0 = 0;

    /** \brief the board contains IR LEDs, this pin controls those LEDs */
    const static int LEDPIN = 29;

    /** \brief determines what constitutes a black line (from -100 to 100)
     * these numbers may be the same, but don't have to be
     */
    const static int ON_THRESHOLD = -0.5;
    const static int OFF_THRESHOLD = -1.5;

    /** \brief account for broken line sensors */
    const static float COMPENSATION = 1.0;

    /** \brief sum of raw line sensor values. used to detect intersections */
    int sum;
};
