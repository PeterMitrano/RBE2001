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

  currentCommandIndex = 0;

  while (!done && (currentCommandIndex < commands.size() )){
    entry = commands.get(currentCommandIndex);
    executingCommand = entry._command;

    bool isFinished = executingCommand->cycle();
    if (isFinished){
     commands.remove(currentCommandIndex);
     currentCommandIndex--;
    }

    if (entry._state == CommandGroupEntry::kSequence_InSequence){
     done = true;
    }
    else {
     currentCommandIndex++;
    }
  }
}

void CommandGroup::end(){}
void CommandGroup::_end(){
}


bool CommandGroup::isFinished(){
  return commands.size() == 0;
}
