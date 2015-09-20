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

bool State::persist(bool bval, String key){
  persist((unsigned long)bval, key);
}

int State::persist(int ival, String key){
  persist((unsigned long)ival, String key);
}

unsigned long State::persist(unsigned long tval, String key){
  if (pvIndex > MAX_PV){
    return false;
  }
  else {
    StatePV *pv = pvArray[pvIndex];
    if (pv != NULL){
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

bool State::operator==(const State& s2) {
  this->id == s2.id;
}

bool State::operator!=(const State& s2) {
  this->id != s2.id;
}
