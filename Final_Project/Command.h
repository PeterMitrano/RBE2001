#pragma once

#include <Arduino.h>

/* this class is the very core of the framework
 * commands are initialized once, then run until they're done
 * completed commands are removed the scheduler
 */

class Command {

  public:
    Command() = default;

    void setTimeout(unsigned long timeout);
    unsigned long getTime();
    bool isTimedOut();

    /* run once in the first iteration of the command's life */
    void initialize();

    /* stuff to do over and over each iteration*/
    void execute();

    /* checked every iteration to see if we're done here */
    bool isFinished();

    /* called once at the end, once isFinished() returned true */
    void end();

    /* adds this command to the scheduler */
    void start();

    /* actually does the  exdcuting */
    bool run();

  private:
    bool initialized;
    unsigned long timeout;
    unsigned long startTime;
};
