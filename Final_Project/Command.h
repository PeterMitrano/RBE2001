/* this class is the very core of the framework
 * commands are initialized once, then run until they're done
 * completed commands are removed the scheduler
 */

class Command {

  public:
    void start();
    void run();
    void cancel();
    void setTimeout(unsigned long timeout);
    bool isCancelled();
    bool isRunning();
    bool isTimedOut();

    // stuff to start with
    void inialize();

    // stuff to do contiuously
    void execute();

    void isFinished();

    void end();

  private:

    CommandGroup *parent;

    unsigned long timeout;
    unsigned long startTime;
    bool running,initialized,canceled;
};
