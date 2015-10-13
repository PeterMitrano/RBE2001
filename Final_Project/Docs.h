/**
 * \mainpage Woah, doxygen is super cool!
 *
 * Here are the dank kids who made this:
 * \Author <a href = "https://petermitrano.github.io">Peter Mitrano</a>,
 * \Author Chris O'Shea,
 * \Author Travis Norris
 *
 * Pictures and Videos are <a href="https://goo.gl/photos/xsBYmbexsEy4SRKu7" >here</a>
 *
 * \section Introduction
 * Sometimes figuring out how a robot works is hard, so we made this nice documentation.
 * Steve operates on a paradigm called "Command Based Programming", as seen in <a href="https://wpilib.screenstepslive.com/s/4485/m/13809/l/241892-what-is-command-based-programming">WPILib</a>
 * Essentially, the main program flow is a combination of commands and command groups. Them main advantages of command based are that it makes changing the robot's routine easy. Base commands like RaiseArm and DriveUntilIntersection are defined, and then composed into commands groups. In our program, the root command group is GetDemRods, which is started in the setup. A Scheduler class is used to keep track of which methods of which commands should run each loop.
 * Along side our command based programming, there are a handful of time-based operations that are called directly in loop. These include:
 *  - \link Robot::playSong \endlink
 *  - \link Robot::blinkLEDs \endlink
 *  - \link Robot::resetTimerFlags \endlink
 *  - \link BTClient::readMessage \endlink
 *  - \link BTClient::sendHeartbeat \endlink
 *  - \link LineSensor::cache \endlink
 *  - \link Arm::control \endlink
 *
 * These functions use flags to determine if they should spin empty or do some work, and commands interract with them by setting those flags. For instance, \link Robot::blinkLEDs \endlink is controlled by the \link Robot::radiating \endlink variable, which is set at the end of commands like GetRodFromReactor.
 *
 * Our project was also featured on Developers Swearing! A twitter full of angry commit messages.
 * <a href='https://twitter.com/gitlost/status/650595667237187584'>Here's the tweet</a>
 *
 */
