#pragma once

#include "PluginManager.h"
#include "timing.h"

class BigClockPlugin : public Plugin
{
private:
  struct tm timeinfo;

  int previousMinutes;
  int previousHour;
  std::vector<int> previousHH;
  std::vector<int> previousMM;
  bool previousLeadingZero;
  static constexpr uint16_t UPDATE_INTERVAL_MS = 1000;

  NonBlockingDelay updateTimer;

  void render();

public:
  void setup() override;
  void loop() override;
  const char *getName() const override;
};
