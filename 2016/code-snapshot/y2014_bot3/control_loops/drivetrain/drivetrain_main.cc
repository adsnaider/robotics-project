#include "aos/linux_code/init.h"

#include "frc971/control_loops/drivetrain/drivetrain.h"
#include "y2014_bot3/control_loops/drivetrain/drivetrain_base.h"

using ::frc971::control_loops::drivetrain::DrivetrainLoop;

int main() {
  ::aos::Init();
  DrivetrainLoop drivetrain(
      ::y2014_bot3::control_loops::drivetrain::GetDrivetrainConfig());
  drivetrain.Run();
  ::aos::Cleanup();
  return 0;
}
