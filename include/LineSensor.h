/* line sensor class
 * functions for reading the line sensor go here
 */

class LineSensor {
  public:

    /* setup servos and stuff. called by main setup */
    void setup();

    /* read intensity of 4 leftmost line sensors as one number */
    int avgLeftIntensity();

    /* read intensity of 4 rightmost line sensors as one number */
    int avgRightIntensity();

    /* returns true if an intersection is detected */
    bool atIntersection();

  private:

     /* read raw values from analog ports */
     int[8] readRaw();

     /* avg 4 sensors, starting at offset from PIN0 */
     int avgSet(int offset);

     /* this assumes line sensor pins are in order. This is the first (leftmost pin) */
     const static int PIN0 = -1;

     /* the board contains IR LEDs, this pin controls those LEDs */
     const static int LED_PIN = -1;

     int[8] rawValues;
}
