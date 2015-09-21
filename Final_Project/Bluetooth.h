#pragma once
/* functions for parsing and sending bluetooth messages */

#include <Robot.h>
#include <Arduino.h>
#include <BluetoothMaster.h>
#include <ReactorProtocol.h>

/* contains bluetooth message data */
class BluetoothClient {
  public:

    /* start serial3 */
    void setup();

    /* read from Serial3 and store into Message instance
     * returns Message if successful, null if unsuccessful
     */
    void readMessage();

  private:

    /* master object */
    BluetoothMaster btMaster;

    /* protocol decoder */
    ReactorProtocol pcol(byte(Robot::TEAM_NUMBER));

    /* raw bytes read by pcol */
    byte rawData[3];

    /* length of data in bytes, seconds bit in rawData */
    int length;

    /* message type
     * TYPES:
     * 1 storage
     * 2 supply
     * 3 radiation
     * 4 stop
     * 5 resume
     * 6 status
     * 7 hearbeat
     * 8-F reserved
     * +10 user defined
     */
     byte messageType;

     /* team number sent by
      * 0 is field
      */
     int source;

     /* team number sent to
      * 0 is everyone
      */
     int dest;

     /* 0xff minus 8-bit sum from offset 1 up to but not including this byte */
     int checksum;
}
