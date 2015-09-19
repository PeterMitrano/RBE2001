#pragma once
/* controls state machine used in robot */

#include <Arduino.h>

/* convenience struct
 * when we want to do a funciton until a ocndition, 
 * ... instead of doing a while loop we call initValue
 * ... which stores that value ONCE and only ONCE in
 * ... an instance struct*/
struct state_pv {
  int ival;
  bool bval;
  /* initValue only writes once
   * this variable keeps track of that */
  bool written;
};
typedef struct state_pv StatePV;


class State {
  public:

    State(String title);

    /* take an initial value and store it in a statePV for later use
     * we have one for bools, and one for ints
     */
    int persist(int ival);
    bool persist(bool bval);
    
    /* convert to text string */
    String toString();
    
    bool operator==(const State& s2);
    bool operator!=(const State& s2);

  private:

    String title;
    int id;
    
    const static int MAX_PV;
    StatePV *pvArray[MAX_PV]; //allows for up to 10 nested states
    int pvIndex = 0;

    static int GLOBAL_ID;
};
