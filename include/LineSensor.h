/* line sensor class
 * functions for reading the line sensor go here
 */

class LineSensor {
  public:

    /* read intensity of 4 leftmost line sensors as one number */
    int avgLeftIntensity();

    /* read intensity of 4 rightmost line sensors as one number */
    int avgRightIntensity();

  private:

     /* read raw values from analog ports */
     int[8] readRaw();

     /* avg left 4 sensors */
     int leftAverage();

     /* avg right 4 sensors */
     int rightAverage();


     int[8] rawValues;
}
