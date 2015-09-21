#pragma once

#include "Arduino.h" //defines NULL

class Command;

class CommandGroupEntry {
 public:
  typedef enum {
    kSequence_InSequence,
    kSequence_InParallel
  } Sequence;

  CommandGroupEntry() = default;
  CommandGroupEntry(Command *command, Sequence state);

  bool operator!=(const CommandGroupEntry& other);

  Command *_command = NULL;
  Sequence _state = kSequence_InSequence;
};
