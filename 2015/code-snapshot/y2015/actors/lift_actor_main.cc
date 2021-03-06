#include <stdio.h>

#include "aos/linux_code/init.h"
#include "y2015/actors/lift_action.q.h"
#include "y2015/actors/lift_actor.h"

int main(int /*argc*/, char* /*argv*/ []) {
  ::aos::Init(-1);

  ::frc971::actors::LiftActor lift(&::frc971::actors::lift_action);
  lift.Run();

  ::aos::Cleanup();
  return 0;
}
