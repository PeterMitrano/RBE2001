#include <LineSensor.h>

LineSensor::setup(){

  for (int i=g_PIN0;i<8;i++){
    pinMode(i,INPUT);
  }
  digitalWrite(LED_PIN,HIGH);
}

int LineSensor::avgSet(int offset){
  int sum;
  for (int i=g_PIN0 + offset;i<4;i++){
    sum += analogRead(i);
  }
  return sum/4;
}

int LineSensor::avgLeftIntensity(){
  return avgSet(0); //avg of 0,1,2,3
}

int LineSensor::avgRightIntensity(){
  return avgSet(4); //avg of 4,5,6,7
}

bool LineSensor::atIntersection(){

}

int[8] LineSensor::readRaw(){
  for (int i=PIN0; i<8; i++){
    rawValues[8] = analogRead(i);
  }
}
