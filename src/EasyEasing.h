#ifndef EasyEasing_h
#define EasyEasing_h

#include "Arduino.h"

//direction + current value
typedef void (*easingHandler)(float);
typedef float (*easingFunction)(float);

class EasyEasing
{
public:
  EasyEasing();
  void start(float, float, unsigned long);
  void setEasing(easingFunction);
  void setHandler(easingHandler);
  void restart();
  void backward();
  int getDirection();
  void setDuration(unsigned long);
  bool inProgress();
  void stop();
  float currentValue();
  void update();
  float easingSquareIn(float) const;
private:
  bool _forceStop;
  float _startVal, _stopVal;
  unsigned long _duration, _startTime;

  easingHandler _handler;
  easingFunction _easing;
};

#endif
