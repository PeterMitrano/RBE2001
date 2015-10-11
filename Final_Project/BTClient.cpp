#include "BTClient.h"
#include "Robot.h"

BTClient::BTClient() :
  pcol(byte(::TEAM_NUMBER)) {
    supply = -1;
    storage = -1;
}

void BTClient::setup(){
  pinMode(14,INPUT_PULLUP);
  pinMode(15,INPUT_PULLUP);
  Serial3.begin(115200);
}

int BTClient::availableSupplyTube(){
  // lookup the first 1 in this byte
  // supply tube 1 is column 4, tub 4 is 1
  if ((supply & 0x1) == 0x1) {return 4;}
  else if ((supply & 0x2) == 0x2) {return 3;}
  else if ((supply & 0x4) == 0x4) {return 2;}
  else if ((supply & 0x8) == 0x8) {return 1;}
  else {
    return -1;
  }
}

bool BTClient::isRodAt(int column){
  return availableSupplyTube() == column;
}

int BTClient::openStorageTube(){
  // storage tube 1 is column 4, tub 4 is 1
  if ((storage & 0x1) != 0x1) {return 4;}
  else if ((storage & 0x2) != 0x2) {return 3;}
  else if ((storage & 0x4) != 0x4) {return 2;}
  else if ((storage & 0x8) != 0x8) {return 1;}
  else {
    return -1;
  }
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
            received_storage = true;
            storage = rawData[0];
            break;
          case SUPPLY_MSG:
            received_supply = true;
            supply = rawData[0];
            break;
          case STOP_MSG:
            Robot::getInstance()->paused = true;
            Serial.println("STOP!!!");
            break;
          case RESUME_MSG:
            Serial.println("RESUME...");
            Robot::getInstance()->paused = false;
          default:
            //only these 4 should be sent by field
            break;
				}
        char tubeInfo[17];
        snprintf(tubeInfo,17,"str=%02i sply=%02i",storage,supply);
//        Robot::getInstance()->debugPrint(tubeInfo);
     }
    }
  }
}

