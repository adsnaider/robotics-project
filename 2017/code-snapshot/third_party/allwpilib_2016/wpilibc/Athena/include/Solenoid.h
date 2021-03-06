/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008-2016. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "SolenoidBase.h"
#if FULL_WPILIB
#include "LiveWindow/LiveWindowSendable.h"
#include "tables/ITableListener.h"
#endif

#include <memory>

/**
 * Solenoid class for running high voltage Digital Output (PCM).
 *
 * The Solenoid class is typically used for pneumatics solenoids, but could be
 * used
 * for any device within the current spec of the PCM.
 */
class Solenoid : public SolenoidBase
#if FULL_WPILIB
                 ,
                 public LiveWindowSendable,
                 public ITableListener
#endif
                 {
 public:
  explicit Solenoid(uint32_t channel);
  Solenoid(uint8_t moduleNumber, uint32_t channel);
  virtual ~Solenoid();
  virtual void Set(bool on);
  virtual bool Get() const;
  bool IsBlackListed() const;

#if FULL_WPILIB
  void ValueChanged(ITable* source, llvm::StringRef key,
                    std::shared_ptr<nt::Value> value, bool isNew);
  void UpdateTable();
  void StartLiveWindowMode();
  void StopLiveWindowMode();
  std::string GetSmartDashboardType() const;
  void InitTable(std::shared_ptr<ITable> subTable);
  std::shared_ptr<ITable> GetTable() const;
#endif

 private:
  uint32_t m_channel;  ///< The channel on the module to control.
#if FULL_WPILIB
  std::shared_ptr<ITable> m_table;
#endif
};
