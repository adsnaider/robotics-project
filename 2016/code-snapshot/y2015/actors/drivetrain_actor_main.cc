#include <stdio.h>

#include "aos/linux_code/init.h"
#include "y2015/actors/drivetrain_action.q.h"
#include "y2015/actors/drivetrain_actor.h"

using ::aos::time::Time;

int main(int /*argc*/, char * /*argv*/[]) {
  ::aos::Init(-1);

  y2015::actors::DrivetrainActor drivetrain(
      &::y2015::actors::drivetrain_action);
  drivetrain.Run();

  ::aos::Cleanup();
  return 0;
}
