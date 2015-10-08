#pragma once

#include <Arduino.h>

/**
 * \brief this class is the very core of the framework
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

    /** \brief run once in the first iteration of the command's life.
     * this will be overrided by individual commands
     * */
    virtual void initialize() = 0;
    virtual void _initialize();

    /** \brief stuff to do over and over each iteration.
     * this will be overrided by individual commands
     */
    virtual void execute() = 0;
    virtual void _execute();

    /** \brief checked every iteration to see if we're done here.
     * this will be overrided by individual commands
     * @return is the function finished
     */
    virtual bool isFinished() = 0;

    /** \brief called once at the end, once isFinished() returned true.
     * this will be overrided by individual commands.
     */
    virtual void end() = 0;
    virtual void _end();

    /** \brief adds this command to the scheduler */
    void start();

    /** \brief actually does the  excuting.
     * @return if command is finished
     */
    bool cycle();

    /** \brief check if the command is running. not yet implemented.
     *  @return if command is still running
     */
    bool isRunning();

    void print();


    String name;

  private:
    bool initialized,running;
    unsigned long timeout;
    unsigned long startTime;
};
