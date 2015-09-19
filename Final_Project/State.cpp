#include "State.h"

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
    if (pv != NULL){ //pk is not empty
      if (!pv->written){
        pv->written = true;
        pv->bval = bval;
      }
    }
    else {
      pv = (StatePV *)malloc(sizeof(StatePV *));
      pv->written = true;
      pv->bval = bval;
      pvIndex++;
    }
    return pv->bval;
  }
}

unsigned long State::persist(unsigned long tval){
  if (pvIndex > MAX_PV){
    return false;
  }
  else {
    StatePV *pv = pvArray[pvIndex];
    if (pv != NULL){ //pk is not empty
      if (!pv->written){
        pv->written = true;
        pv->tval = tval;
      }
    }
    else {
      pv = (StatePV *)malloc(sizeof(StatePV *));
      pv->written = true;
      pv->tval = tval;
      pvIndex++;
    }
    return pv->tval;
  }
}

int State::persist(int ival){
  if (pvIndex > MAX_PV){
    return false;
  }
  else {
    StatePV *pv = pvArray[pvIndex];
    if (pv != NULL){ //pv is not empty
      if (!pv->written){
        pv->written = true;
        pv->ival = ival;
      }
    }
    else {
      pv = (StatePV *)malloc(sizeof(StatePV *));
      pv->written = true;
      pv->ival = ival;
      pvIndex++;
    }
    return pv->ival;
  }
}

bool State::operator==(const State& s2) {
  this->id == s2.id;
}

bool State::operator!=(const State& s2) {
  this->id != s2.id;
}
