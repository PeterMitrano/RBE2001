#include "Bluetooth.h"

void BluetoothClient::setup(){
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
