#pragma once

class Command;

class CommandGroupEntry {
  public:
    typedef num {
      kSquence_InSequence;
      kSequence_BranchPeer;
      kSequence_BranchChild;
    } Sequence;

CommandGroupEntry(Command *command, Sequence state, double timeout = -1.0);


}
