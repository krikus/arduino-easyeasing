#include "EasyEasing.h"

EasyEasing::EasyEasing()
{
  _forceStop = true;
  _startVal = _stopVal = 0;
  _duration = _startTime = 0;
  _handler = NULL;
  _easing = NULL;
}

void EasyEasing::start(float initValue, float finalValue, unsigned long duration){
  _startVal = initValue;
  _stopVal = finalValue;
  _duration = duration;
  restart();
}

void EasyEasing::setHandler(easingHandler h){
  _handler = h;
}

void EasyEasing::setEasing(easingFunction e){
  _easing = e;
}

void EasyEasing::restart(){
  _forceStop = false;
  _startTime = millis();
}

void EasyEasing::backward(){
  _forceStop = false;
  float tmp = _stopVal;
  _stopVal = _startVal;
  _startVal = tmp;
  _startTime = millis();
}

int EasyEasing::getDirection(){
  return (_startVal > _stopVal) ? -1 : 1;
}

void EasyEasing::setDuration(unsigned long duration){
  _duration = duration;
}

bool EasyEasing::inProgress(){
  return (!_forceStop && (millis() - _startTime) < _duration);
}

void EasyEasing::stop(){
  _forceStop=true;
}

float EasyEasing::currentValue(){
  unsigned long diff = (millis() - _startTime);
  if (diff<_duration){
    float p = _easing ? _easing((float)diff/_duration) : (float)diff/_duration;
    return _startVal + (_stopVal-_startVal)*p;
  }else{
    _forceStop = true;
    return _stopVal;
  }
}

void EasyEasing::update(){
  if (!_forceStop && _handler){
    float v = currentValue();
    _handler(v);
  }
}
