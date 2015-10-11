#pragma once
/** \brief
 * functions for reading the position with respect to the line
 */

class LineSensor {
  public:

    /** \brief boring contsructor */
    LineSensor();

    /** \brief setup servos and stuff. called by main setup */
    void setup();

    /** \brief scale sensor value between it's min and max.
     * \param[_in] sensorValue the current value of the sensor
     * \param[_in[ sensorPosition the position of the sensor given
     * \return number from -100 to 100
     */
    int scale(int sensorValue, int sensorPosition);

    /** \brief captures min and max line sensor values*/
    void calibrateLineSensors();

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
    const static float ON_POS_THRESHOLD = 0.4;

    /** PID constants for line following */
    const float kP = 11.0;
    const float kD = 5.0;
    int derivative;

    /** \brief account for broken line sensors */
    const static float COMPENSATION = 1;

    /** \brief test if we're at a line */
    const static int INTERSECTION_THRESHOLD = 0;
    const static int LOW_SUM_THRESHOLD = -500;
    const static int HIGH_SUM_THRESHOLD = -200;

    /** \brief sum of raw line sensor values. used to detect intersections */
    int sum;

    /** \brief contains the min and maxes for each line sensor.
     * the first row is for min, and the second row is for max*/
    int limits[8][2];

    /** \brief contains the raw values for each line sensor */
    int rawValues[8];
};
