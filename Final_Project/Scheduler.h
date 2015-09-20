/* scheduler is the master of all commands
 * It knows executes the inialize, execute, and end functions
 * of each commands
 *
 * Scheduler is also a singleton, so the constructor is private
 * and there's only one instance
 */

class Scheduler {
  public:
    static Scheduler *GetInstance();
    void AddCommand(Command *command);
    void Run();

  private:
    Scheduler();

    typedef LinkedList<Command *> CommandList;

    CommandList m_additions;
    CommandList commands;

    bool m_adding;
    bool m_enabled = true;

};
