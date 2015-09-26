#pragma once
/* functions for parsing and sending bluetooth messages
 * Bluetooth is checked every loop and stored in member variables in this clas
 * when a command wants to get the location of the tubes, it can do so instantaneously
 * by looking at the last stored value
 * */

#include "Util.h"
#include <BluetoothMaster.h>
#include <ReactorProtocol.h>

/* contains bluetooth message data */
class BTClient {
  public:

    /* constructor initializes btmaster and pcol */
    BTClient();

    /* start serial3 */
    void setup();

    /* returns the supply tub locations */
    byte availableSupplyTubes();

    /* returns the storage tub locations */
    byte openStorageTubes();

    /* send 0xff to the field computer */
    void sendRadiationAlert();

    /* send 0x00 to field computer */
    void sendHeartbeat();

    /* send string to field computer for debugging */
    void sendDebugString(String message);

    /* read from Serial3 and store into Message instance
     * returns Message if successful, null if unsuccessful
     */
    void readMessage();

  private:

     typedef enum {STORAGE_MSG = 0x01,
           SUPPLY_MSG = 0x02,
           RADIATION_MSG = 0x03,
           STOP_MSG = 0x04,
           RESUME_MSG = 0x05,
           STATUS_MSG = 0x06,
           HEARTBEAT_MSG = 0x07,
           DEBUG_MSG = 0x10,
           WARN_MSG = 0x11,
           INFO_MSG = 0x12} MSG_TYPE;

    /* send the given data to the field computer */
    void sendData(byte data[3]);

    /* master object */
    BluetoothMaster btMaster;

    /* protocol decoder */
    ReactorProtocol pcol;

    /* set by commands to tell us when to send data */
    bool sending;

    /* raw integer (or hex if you life) representation for storage and supply */
    int storage, supply;

};
