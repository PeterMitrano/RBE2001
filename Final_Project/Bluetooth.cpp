#include "Bluetooth.h"

BluetoothClient::BluetoothClient() :
  pcol(byte(TEAM_NUMBER))
{}

void BluetoothClient::setup(){
  pinMode(14,INPUT_PULLUP);
  pinMode(15,INPUT_PULLUP);
  Serial3.begin(115200);
}

void BluetoothClient::readMessage(){
  byte pkt[10];
  if (btMaster.readPacket(pkt)){
    if (pcol.getData(pkt,rawData,messageType)){
      //switch on type?
    }
  }
}
