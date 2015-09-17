#pragma once
/* controls state machine used in robot */

#include <Arduino.h>

class State {
  public:

    State(String title);

    /* convert to text string */
    String toString();
    
    /* I am before s */
    void before(State s);

    /* I am after s */
    void after(State s);

    bool isAfter(State s);
    bool isBefore(State s);

    bool operator==(const State& s2);
    bool operator!=(const State& s2);

  private:

    static int GLOBAL_ID;
    State* beforeState;
    State* afterState;
    String title;
    int id;

};
