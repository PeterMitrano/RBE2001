#include "CommandGroup.h"
#include "CommandGroupEntry.h"

void CommandGroup::addSequential(Command *command){
  commands.add(
      CommandGroupEntry(command, CommandGroupEntry::kSequence_InSequence));
}

void CommandGroup::addParallel(Command *command){
  commands.add(
      CommandGroupEntry(command, CommandGroupEntry::kSequence_InParallel));
}

void CommandGroup::_initialize(){
  currentCommandIndex = -1;
}

void CommandGroup::_execute(){
  CommandGroupEntry entry;
  Command *executingCommand = NULL;
  bool done = false;

  if (currentCommandIndex  == -1){
    currentCommandIndex = 0;
  }

  while (!done && (currentCommandIndex < commands.size() )){
    if (executingCommand != NULL){
      bool isFinished = executingCommand->run();
      if (!isFinished){
        currentCommandIndex++;
        executingCommand = NULL;
        continue;
      }
      else {
        done = true;
      }
    }

    entry = commands.get(currentCommandIndex);
    executingCommand = NULL;

    switch(entry._state){
      case CommandGroupEntry::kSequence_InSequence:
        executingCommand = entry._command;
        break;

      case CommandGroupEntry::kSequence_InParallel:
        currentCommandIndex++;
        entry._command->run();
        break;
    }


  }



}

void CommandGroup::_isFinished(){
}

void CommandGroup::_end(){
}
