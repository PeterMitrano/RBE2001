#pragma once

/** \brief
 * functions for reading the position with respect to the line
 */

#include <QTRSensors.h>

class LineSensor {
  public:

    /** \brief boring contsructor */
    LineSensor();

    /** \brief setup servos and stuff. called by main setup */
    void setup();

    /** \brief captures min and max line sensor values*/
    void calibrateLineSensors();

    /** \brief returns true if both sensors are on the line */
    bool atIntersection();

    /** \brief returns true if both sensors are off the line */
    bool notAtIntersection();

    /** \brief returns if line sensor is on the line */
    bool onLine();

    /** \brief returns if the line is on the far left */
    bool lineFarLeft();

    /** \brief returns if the line is on the far right */
    bool lineFarRight();

    /** \brief does raw read and storage of line sensor. This must be caled every loop
     */
    void cache();

    /** \brief get how much motor power you should adjust by. from -100 to 100 */
    int adjustmentPower();

    const static int LEFT_EDGE = 1, RIGHT_EDGE = -1;

  private:

    /** \brief the Pululo library line sensor object */
    QTRSensorsRC sensor;

    /** \brief holds the line position as calculated by cache. On scale of tens */
    float linePosition;
    float lastLinePosition;

    /** \brief the board contains IR LEDs, this pin controls those LEDs */
    const static int LEDPIN = 29;

    /** \brief the other pins */
    static unsigned char PINS[8];

    /** \brief determines what constitutes a black line (from -100 to 100)
     * these numbers may be the same, but don't have to be
     */
    const static float ON_POS_THRESHOLD = 100;

    /** PID constants for line following */
    const float kP = 0.007;
    const float kD = 0.1;
    int derivative;

    /** \brief if all 8 sensors are 90% black, we've reached an intersection */
    const static int INTERSECTION_THRESHOLD = 8 * 950;
    const static int NO_INTERSECTION_THRESHOLD = 8 * 300;

    const static int LEFT_THRESHOLD = 1000;
    const static int RIGHT_THRESHOLD = -500;

    /** \brief sum of raw line sensor values. used to detect intersections */
    int sum;

    /** \brief contains the raw values for each line sensor */
    unsigned int rawValues[8];

    /** \brief number of sensors */
    const static unsigned char NUM_SENSORS = 8;

    /** \brief timeout for the RC reading of the line sensors */
    const static int TIMEOUT = 2500;
};
