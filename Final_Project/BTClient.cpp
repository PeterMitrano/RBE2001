#include "BTClient.h"

#include "Robot.h"

BTClient::BTClient() :
  pcol(byte(::TEAM_NUMBER)) {
}

void BTClient::setup(){
  Serial3.begin(115200);
}

byte BTClient::availableSupplyTubes(){

}

byte BTClient::openStorageTubes(){

}

void BTClient::sendRadiationAlert(){

}

void BTClient::sendHeartbeat(){

}

void BTClient::sendDebugString(String message){

}

void BTClient::sendData(byte data[3]){
  if (sending){
    byte pkt[10];
    pcol.setDst(0x00);
    int sz = pcol.createPkt(RADIATION_MSG, data, pkt);
    btMaster.sendPkt(pkt, sz);
  }
}

void BTClient::readMessage(){
  byte pkt[10];
  byte rawData[3];
  byte messageType;
  if (btMaster.readPacket(pkt)){
    //don't care about ones not for us
    if (pkt[3] == TEAM_NUMBER){
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

