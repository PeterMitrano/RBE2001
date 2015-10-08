#pragma once
/* scheduler is the master of all commands
 * It knows executes the inialize, execute, and end functions
 * of each commands
 *
 * Scheduler is also a singleton, so the constructor is private
 * and there's only one instance
 */

#include "LinkedList.h"
#include "Command.h"

class Scheduler {
  public:
    static Scheduler *getInstance();
    void addCommand(Command *command);
    void printCurrentCommands();
    void run();
    void print();

  private:
    Scheduler();
    static Scheduler *instance;

    LinkedList<Command *> commands;
};
