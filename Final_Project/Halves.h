#pragma once

#include "CommandGroup.h"

class FirstHalf: public CommandGroup {
  public:
    FirstHalf();
    void initialize();
    void end();
};

class SecondHalf: public CommandGroup {
  public:
    SecondHalf();
    void initialize();
    void end();
};
