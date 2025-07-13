#include "plugins/ClockPlugin.h"

void ClockPlugin::setup()
{
  // loading screen
  Screen.setPixel(4, 7, 1);
  Screen.setPixel(5, 7, 1);
  Screen.setPixel(7, 7, 1);
  Screen.setPixel(8, 7, 1);
  Screen.setPixel(10, 7, 1);
  Screen.setPixel(11, 7, 1);

  previousMinutes = -1;
  previousHour = -1;
}

void ClockPlugin::loop()
{
  if (getLocalTime(&timeinfo))
  {
    if (previousHour != timeinfo.tm_hour || previousMinutes != timeinfo.tm_min)
    {
      previousMinutes = timeinfo.tm_min;
      previousHour = timeinfo.tm_hour;
    }
    Screen.clear();
    Screen.drawNumbers(3, 2, {(previousHour - previousHour % 10) / 10, previousHour % 10});
    Screen.drawNumbers(3, 8, {(previousMinutes - previousMinutes % 10) / 10, previousMinutes % 10});
    Screen.swapBuffers();
  }
}

const char *ClockPlugin::getName() const
{
  return "Clock";
}
