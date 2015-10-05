#include "BackOffTube.h"
#include "Robot.h"

BackOffTube::BackOffTube() : Command ("Back off tube"){

}

void BackOffTube::initialize(){
	Robot.getInstance()->Robot.driveBwd();
	startTime=millis();
}

void BackOffTube::execute(){

}

bool BackOffTube::isFinished(){
	return (millis() > startTime + waitTime);
}

void BackOffTube::end()
{
	Robot.getInstance()->Robot.stopDriving();
}