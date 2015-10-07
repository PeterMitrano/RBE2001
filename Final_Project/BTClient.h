#pragma once
/** \brief functions for parsing and sending bluetooth messages
 * Bluetooth is checked every loop and stored in member variables in this clas
 * when a command wants to get the location of the tubes, it can do so instantaneously
 * by looking at the last stored value
 * */

#include "Util.h"
#include <BluetoothMaster.h>
#include <ReactorProtocol.h>

class BTClient {
  public:

    /** \brief constructor initializes btmaster and pcol */
    BTClient();

    /** \brief start serial3 */
    void setup();

    /** \brief returns the supply tub locations
     * \return the position of the available supply tube */
    int availableSupplyTube();

    /** \brief returns the storage tub locations
     * \return the position of the open storage tube */
    int openStorageTube();

    /** \brief send 0xff to the field computer */
    void sendRadiationAlert();

    /** \brief send 0x00 to field computer */
    void sendHeartbeat();

    /** \brief send string to field computer for debugging */
    void sendDebugString(String message);

    /** \brief send status */
    void sendStatus();

    /** \brief read from Serial3 and store into Message instance
     * returns Message if successful, null if unsuccessful
     */
    void readMessage();

    /** \brief status variables for sending messages */
    int movementStatus,gripperStatus,operationStatus;

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

    /** \brief send the given data to the field computer */
    void sendData(MSG_TYPE type, byte data[3]);

    /** \brief master object */
    BluetoothMaster btMaster;

    /** \brief protocol decoder */
    ReactorProtocol pcol;

    unsigned long lastSent;
    bool received_storage = false,
         received_supply = false;

    /** \brief raw integer (or hex if you want) representation for storage and supply */
    int storage, supply;
};
