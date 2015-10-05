#include "BTClient.h"
#include "Robot.h"

const int BTClient::locationLookup[] = {
    1,2,1,3,1,2,1,4,1,2,1,3,12,1
  };

BTClient::BTClient() :
  pcol(byte(::TEAM_NUMBER)) {
}

void BTClient::setup(){
  pinMode(14,INPUT_PULLUP);
  pinMode(15,INPUT_PULLUP);
  Serial3.begin(115200);
}

byte BTClient::availableSupplyTube(){
  // lookup the first 1 in this byte
  return locationLookup[supply];
}

byte BTClient::openStorageTube(){
  // lookup the first 1 in this byte
  return locationLookup[storage];
}

void BTClient::sendRadiationAlert(){
  sendData(RADIATION_MSG, NULL);
}

void BTClient::sendHeartbeat(){
  sendData(HEARTBEAT_MSG, NULL);
}

void BTClient::sendStatus(){
  byte status[3];
//  = {movementStatus,
//    gripperStatus,
//    operationStatus};
  sendData(STATUS_MSG, status);
}

void BTClient::sendDebugString(String message){

}

void BTClient::sendData(MSG_TYPE type, byte data[3]){
  unsigned long t = millis();
  unsigned long dt = t - lastSent;
  if (dt > 1500){
    lastSent = t;
    byte pkt[10];
    pcol.setDst(0x00);
    int sz = pcol.createPkt(type, data, pkt);
    btMaster.sendPkt(pkt, sz);
  }
}

void BTClient::readMessage(){
  byte pkt[10];
  byte rawData[3];
  byte messageType;

  if (btMaster.readPacket(pkt)){
    //don't care about ones not for us
    if (pkt[4] == TEAM_NUMBER || pkt[4] == 0){
      if (pcol.getData(pkt,rawData,messageType)){
        switch(messageType){
          case STORAGE_MSG:
             storage = rawData[0];
            break;
          case SUPPLY_MSG:
             supply = rawData[0];
            break;
          case STOP_MSG:
            Robot::getInstance()->paused = true;
            break;
          case RESUME_MSG:
            Robot::getInstance()->paused = false;
          default:
            //only these 4 should be sent by field
            break;
        }
      }
    }
  }
}

