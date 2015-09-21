#include "CommandGroup.h"
#include "CommandGroupEntry.h"

CommandGroup::CommandGroup(const String name) : Command(name) {}

void CommandGroup::addSequential(Command *command){
  commands.add(
      CommandGroupEntry(command, CommandGroupEntry::kSequence_InSequence));
}

void CommandGroup::addParallel(Command *command){
  commands.add(
      CommandGroupEntry(command, CommandGroupEntry::kSequence_InParallel));
}

void CommandGroup::initialize(){}
void CommandGroup::_initialize(){
  currentCommandIndex = -1;
}

void CommandGroup::execute(){}
void CommandGroup::_execute(){

  CommandGroupEntry entry;
  Command *executingCommand = NULL;
  bool done = false;

  if (currentCommandIndex  == -1){
    currentCommandIndex = 0;
  }

  while (!done && (currentCommandIndex < commands.size() )){

    if (executingCommand != NULL){
      bool isFinished = executingCommand->cycle();
      if (!isFinished){
        done = true;
      }
      else {
        commands.remove(currentCommandIndex);
      }
    }

    entry = commands.get(currentCommandIndex);

    switch(entry._state){
      case CommandGroupEntry::kSequence_InSequence:
        executingCommand = entry._command;
        break;
      case CommandGroupEntry::kSequence_InParallel:
        currentCommandIndex++;
        entry._command->cycle();
        break;
    }
  }
}

void CommandGroup::end(){}
void CommandGroup::_end(){
}


bool CommandGroup::isFinished(){
  return commands.size() == 0;
}
