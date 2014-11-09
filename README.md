arduino-easyeasing
==================

Library for arduino that implements easing over time.

This library does not use interrupts, you must manually call `update()` in main loop.
You should not use any long delays in your code - for the best is to use `millis()` instead.

==================

For start you need to new object using `EasyEasing es = new EasyEasing()`. This object has following public methods:

void start(float, float, unsigned long); // inits the easing values - start value, stop value, duration in milliseconds

void setEasing(easingFunction); // optional easing function

void setHandler(easingHandler); // handler function - called when value changes

void restart(); // restarts easing

void backward(); // starts easing in reverse mode

int getDirection(); // -1 for descending and 1 for ascending values

void setDuration(unsigned long); // changes duration of easing

bool inProgress(); // true if easing is in progress

void stop(); // forcefully stops easing

float currentValue(); // peak the current easing value

void update(); // update value of easing depending on time passed - also calls easing handler if easing is in progress

float easingSquareIn(float); // function that can be passed as easingFunction it uses x^2-2x as easing function.


==================

For more information please see included examples.
