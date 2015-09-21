#pragma once

#include "Command.h"
#include "CommandGroupEntry.h"
#include "LinkedList.h"

/* grouping commands is a useful abstraction
 * commands groups execute commands in parallel or series
 */

class CommandGroup: public Command {
  public:
    CommandGroup(const String name);
    CommandGroup() = default;

    void addSequential(Command *command);
    void addParallel(Command *command);

    virtual void _initialize();
    virtual void _execute();
    virtual void _end();

    virtual void initialize();
    virtual void execute();
    virtual void end();
    virtual bool isFinished();

  private:

    int currentCommandIndex;

    LinkedList<CommandGroupEntry> commands;
};
