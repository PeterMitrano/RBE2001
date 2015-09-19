#include "BTClient.h"

BTClient::BTClient() :
  pcol(byte(::TEAM_NUMBER)) {
}

void BTClient::setup(){
  Serial3.begin(115200);
}

void BTClient::readMessage(){
  byte pkt[10];
  if (btMaster.readPacket(pkt)){
    if (pcol.getData(pkt,rawData,messageType)){
      //switch on type?
    }
  }
}

