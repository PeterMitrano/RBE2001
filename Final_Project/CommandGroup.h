#pragma once

#include "Command.h"
#include "CommandGroupEntry.h"
#include "LinkedList.h"

/* grouping commands is a useful abstraction
 * commands groups execute commands in parallel or series
 */

class CommandGroup: public Command {
  public:
    CommandGroup() = default;

    void addSequential(Command *command);
    void addParallel(Command *command);

    void _initialize();

    void _execute();

    void _isFinished();

    void _end();

  private:

    int currentCommandIndex;

    LinkedList<CommandGroupEntry> commands;
};
