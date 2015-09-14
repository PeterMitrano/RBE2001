#include <State.h>

void State::before(State s){
  beforeState = s;
}

void State::after(State s){
  afterState = s;
}

bool State::isAfter(State s){
  return (afterState == s) || (afterState.isAfter(s));
}

bool State::isBefore(State s){
  return (beforeState == s) || (beforeState.isBefore(s));
}

/* the actual states are defined below */
const static State SETUP, CALIBRATING;
