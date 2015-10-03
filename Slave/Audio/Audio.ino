//coprocessor code here
#include <Wire.h>

void setup(){
  Wire.begin(1);
  Wire.onReceive(dataEvent);
}

void loop(){}

void dataEvent(){
  if (Wire.available() ==  1){
    int currrentCommand = Wire.read();
  }
}
