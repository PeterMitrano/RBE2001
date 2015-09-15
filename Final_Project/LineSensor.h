/* line sensor class
 * functions for reading the line sensor go here
 */

class LineSensor {
  public:

    /* setup servos and stuff. called by main setup */
    void setup();

    /* read intensity of 4 leftmost line sensors as one number from -100 to 100 */
    int avgLeftIntensity();

    /* read intensity of 4 rightmost line sensors as one number from -100 to 100 */
    int avgRightIntensity();

    /* returns true if both sensors are on the line */
    bool atIntersection();

    /* returns if either line sensor is one the line */
    bool onLine();

    /* set min
     * min should be on a scale of 0 to 1024, since it's a raw sensor value
     */
    void setMin(int min);

    /* set max
     * max should be on a scale of 0 to 1024, since it's a raw sensor value
     */
    void setMax(int max);

    /* call THESHOLD_PERCENT of the raw sensor value range as "on the line"
     * again, the resuling threshold is from 0 to 1024
     */
    void calculateThreshold();

    /* return raw value of 4th sensor
     * yes, I realized it's not actually the center
     */
    int rawCenterSensor();

  private:

    /* returns true if the right line sensor is ablove line threashold */
    bool rightSideOnLine();

    /* returns true if the left line sensor is ablove line threashold */
    bool leftSideOnLine();

    /* read raw values from analog ports */
    int* readRaw();

    /* avg 4 sensors, starting at offset from PIN0
     * value scaled from -100 to 100
     */
    int avgSet(int offset);

    /* this assumes line sensor pins are in order. This is the first (leftmost pin) */
    const static int PIN0 = -1;

    /* the board contains IR LEDs, this pin controls those LEDs */
    const static int LED_PIN = -1;

    /* raw min value, from 0 to 1024 */
    int min_intensity;

    /* raw max value, from 0 to 1024 */
    int max_intensity;

    /* this is the cut_off for what constitutes "on the line"
     * it is calculated after calibration is compete
     */
    int line_threshold = -1;

    /* used by calculate threshold, based on min and max from calibrate */
    const static float THRESHOLD_PERCENT = 0.65;

    int rawValues[8];
};
