/* grouping commands is a useful abstraction
 * commands groups execute commands in parallel or series
 */

class CommandGroup {
  public:

  void addSequential(Command *command);
  void addParallel(Command *command);

  void initialize();

  void execute();

  void isFinished();

  void end();

  private:

  LinkedList<CommandGroupEntry> commands;

  LinkedList<CommandGroupEntry> children;

};
