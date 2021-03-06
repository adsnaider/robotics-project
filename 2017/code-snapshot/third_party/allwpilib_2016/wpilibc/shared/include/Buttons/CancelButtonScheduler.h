/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011-2016. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef __CANCEL_BUTTON_SCHEDULER_H__
#define __CANCEL_BUTTON_SCHEDULER_H__

#include "Buttons/ButtonScheduler.h"

class Trigger;
class Command;

class CancelButtonScheduler : public ButtonScheduler {
 public:
  CancelButtonScheduler(bool last, Trigger *button, Command *orders);
  virtual ~CancelButtonScheduler() = default;
  virtual void Execute();

 private:
  bool pressedLast;
};

#endif
