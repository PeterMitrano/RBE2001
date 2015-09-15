/* controls state machine used in robot */

class State {
  public:

    /* I am before s */
    void before(State s);

    /* I am after s */
    void after(State s);

    bool isAfter(State s);
    bool isBefore(State s);

  private:

    /* private constructor
     * this is because states are static and can't be created by anyone else
     */
    void State();
}
