/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.
 */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/
#pragma once

#include "ErrorBase.h"
#include "Task.h"
#include <map>
#include <string>
#include <vector>
#include "HAL/cpp/Semaphore.hpp"
#include "tables/ITableListener.h"
#include "networktables/NetworkTable.h"

/**
 * The preferences class provides a relatively simple way to save important
 * values to
 * the RoboRIO to access the next time the RoboRIO is booted.
 *
 * <p>This class loads and saves from a file
 * inside the RoboRIO.  The user can not access the file directly, but may
 * modify values at specific
 * fields which will then be automatically periodically saved to the file
 * by the NetworkTable server.</p>
 *
 * <p>This class is thread safe.</p>
 *
 * <p>This will also interact with {@link NetworkTable} by creating a table
 * called "Preferences" with all the key-value pairs.</p>
 */
class Preferences : public ErrorBase {
 public:
  static Preferences *GetInstance();

  std::vector<std::string> GetKeys();
  std::string GetString(llvm::StringRef key, llvm::StringRef defaultValue = "");
  int GetInt(llvm::StringRef key, int defaultValue = 0);
  double GetDouble(llvm::StringRef key, double defaultValue = 0.0);
  float GetFloat(llvm::StringRef key, float defaultValue = 0.0);
  bool GetBoolean(llvm::StringRef key, bool defaultValue = false);
  int64_t GetLong(llvm::StringRef key, int64_t defaultValue = 0);
  void PutString(llvm::StringRef key, llvm::StringRef value);
  void PutInt(llvm::StringRef key, int value);
  void PutDouble(llvm::StringRef key, double value);
  void PutFloat(llvm::StringRef key, float value);
  void PutBoolean(llvm::StringRef key, bool value);
  void PutLong(llvm::StringRef key, int64_t value);
  DEPRECATED(
      "Saving is now automatically performed by the NetworkTables server.")
  void Save();
  bool ContainsKey(llvm::StringRef key);
  void Remove(llvm::StringRef key);

 protected:
  Preferences();
  virtual ~Preferences() = default;

 private:
  std::shared_ptr<ITable> m_table;
  class Listener : public ITableListener {
   public:
    void ValueChanged(ITable* source, llvm::StringRef key,
                      std::shared_ptr<nt::Value> value, bool isNew) override;
    void ValueChangedEx(ITable* source, llvm::StringRef key,
                        std::shared_ptr<nt::Value> value,
                        unsigned int flags) override;
  };
  Listener m_listener;
};
