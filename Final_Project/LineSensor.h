#pragma once
/** line sensor class
 * functions for reading the line sensor go here
 */

class LineSensor {
  public:

    /** \brief setup servos and stuff. called by main setup */
    void setup();

    /** \brief read intensity of 4 leftmost line sensors as one number from -100 to 100 */
    int avgLeftIntensity();

    /** \brief read intensity of 4 rightmost line sensors as one number from -100 to 100 */
    int avgRightIntensity();

    /** \brief returns true if both sensors are on the line */
    bool atIntersection();

    /** \brief returns if either line sensor is one the line */
    bool onLine();

    /** calculate THESHOLD of the raw sensor value range as "on the line"
     * again, the resuling threshold is from 0 to 1024
     */
    void setMinMax(int minVal, int maxVal);

    /** \brief values used during calibration
     */
    int calibratingValue();


    /** returns true if the right line sensor is ablove line threashold */
    bool rightSideOnLine();
    bool rightSideOffLine();

    /** returns true if the left line sensor is ablove line threashold */
    bool leftSideOnLine();
    bool leftSideOffLine();

    /** \brief does raw read and storage of line sensor. This must be caled every loop
     */
    void cache();


  private:

    /** avg 4 sensors, starting at offset from PIN_0
     * value scaled from -100 to 100
     */
    int avgSet(int offset);

    /** scale 0 to 1024 ti -100 to 100 */
    int scale(int avg);

    /** this assumes line sensor pins are in order. This is the first (leftmost pin) */
    const static int PIN_0 = 0;

    /** \brief the board contains IR LEDs, this pin controls those LEDs */
    const static int LEDPIN = 29;

    /** \brief raw min value, from 0 to 1024 */
    int min_intensity;

    /** \brief raw max value, from 0 to 1024 */
    int max_intensity;

    /** \brief determines what constitutes a black line (from -100 to 100)
     * these numbers may be the same, but don't have to be
     */
    const static int ON_THRESHOLD = 75;
    const static int OFF_THRESHOLD = -85;

    /** \brief used to pad min and max (on a scale of 1024), since scanning isn't perfect */
    const static int PADDING = 35;

    /** \brief hold the last 2 values of all the sensors */
    int raw_vals[24];
};
