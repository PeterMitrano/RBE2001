#pragma once

#include <Arduino.h>

/* this class is the very core of the framework
 * commands are initialized once, then run until they're done
 * completed commands are removed the scheduler
 */

class Command {

  public:
    Command();
    Command(const String name);

    void setTimeout(unsigned long timeout);
    unsigned long getTime();
    bool isTimedOut();

    /* run once in the first iteration of the command's life */
    virtual void initialize() = 0;
    virtual void _initialize();

    /* stuff to do over and over each iteration*/
    virtual void execute() = 0;
    virtual void _execute();

    /* checked every iteration to see if we're done here */
    virtual bool isFinished() = 0; 

    /* called once at the end, once isFinished() returned true */
    virtual void end() = 0;
    virtual void _end();

    /* adds this command to the scheduler */
    void start();

    /* actually does the  excuting */
    bool cycle();

    bool isRunning();

    String name;

  private:
    bool initialized,running;
    unsigned long timeout;
    unsigned long startTime;
};
