#include "State.h"

int State::GLOBAL_ID = 0;

State::State(String title) {
  this->title = title;
  this->id = State::GLOBAL_ID++;
}

String State::toString(){
  return title;  
}

void State::before(State s) {
  beforeState = &s;
}

void State::after(State s) {
  afterState = &s;
}

bool State::isAfter(State s) {
  return (*afterState == s) || (afterState->isAfter(s));
}

bool State::isBefore(State s) {
  return (*beforeState == s) || (beforeState->isBefore(s));
}

bool State::operator==(const State& s2) {
  this->id == s2.id;
}

bool State::operator!=(const State& s2) {
  this->id != s2.id;
}
