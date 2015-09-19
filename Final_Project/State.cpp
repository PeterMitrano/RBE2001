#include "State.h"

int State::MAX_PV = 10;
int State::GLOBAL_ID = 0;

State::State(String title) {
  this->title = title;
  this->id = State::GLOBAL_ID++;
  this->pvIndex = 0;
}

String State::toString(){
  return title;  
}

bool State::persist(bool bval){
  if (pvIndex > MAX_PV){
    return false;  
  }
  else {
    StatePV *pv = pvArray[pvIndex];
    if (pv != null){ //pk is not empty
      if (!pv.written){
        pv.written = true;
        pv.key = key;
        pv.bval = bval;
      }
    }
    else {
      pv = malloc(sizeof(StatePV *));
      pv.written = true;
      pv.key = key;
      pv.bval = bval;
      pvIndex++;
    }
    return pv.bval;
  }
}

int State::persist(int ival){
  if (pvIndex > MAX_PV){
    return false;  
  }
  else {
    StatePV *pv = pvArray[pvIndex];
    if (pv != null){ //pv is not empty
      if (!pv.written){
        pv.written = true;
        pv.key = key;
        pv.ival = ival;
      }
    }
    else {
      pv = malloc(sizeof(StatePV *));
      pv.written = true;
      pv.key = key;
      pv.ival = ival;
      pvIndex++;
    }
    return pv.ival;
  }
}

bool State::operator==(const State& s2) {
  this->id == s2.id;
}

bool State::operator!=(const State& s2) {
  this->id != s2.id;
}
