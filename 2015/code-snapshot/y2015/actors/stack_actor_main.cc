#include <stdio.h>

#include "aos/linux_code/init.h"
#include "y2015/actors/stack_action.q.h"
#include "y2015/actors/stack_actor.h"

int main(int /*argc*/, char* /*argv*/ []) {
  ::aos::Init(-1);

  ::frc971::actors::StackActor stack(&::frc971::actors::stack_action);
  stack.Run();

  ::aos::Cleanup();
  return 0;
}
