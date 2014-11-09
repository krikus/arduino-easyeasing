arduino-easyeasing
==================

Library for arduino that implements easing over time.

This library does not use interrupts, you must manually call update() in main loop.
You should not use any long delays in your code - for the best is to use millis() instead.
