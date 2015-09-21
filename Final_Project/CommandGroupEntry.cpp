#include "CommandGroupEntry.h"
#include "Command.h"

CommandGroupEntry::CommandGroupEntry(Command *command, CommandGroupEntry::Sequence state) :
  _command(command),
  _state(state)
{}

bool CommandGroupEntry::operator!=(const CommandGroupEntry& other){
  return this->_command != other._command;
}
