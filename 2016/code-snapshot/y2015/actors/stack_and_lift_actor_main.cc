#include <stdio.h>

#include "aos/linux_code/init.h"
#include "y2015/actors/stack_and_lift_action.q.h"
#include "y2015/actors/stack_and_lift_actor.h"

int main(int /*argc*/, char* /*argv*/ []) {
  ::aos::Init(-1);

  ::y2015::actors::StackAndLiftActor stack_and_lift(
      &::y2015::actors::stack_and_lift_action);
  stack_and_lift.Run();

  ::aos::Cleanup();
  return 0;
}
