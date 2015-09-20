#include "Robot.h"
#include "Scheduler.h"

void setup() {
  Serial.begin(9600);
  alan.setup();

  GetDemRods *gdr = new GetDemRods();
  gdr->start();
}

void loop() {
  Scheduler.getInstance->run();
}
