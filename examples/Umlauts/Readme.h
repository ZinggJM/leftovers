/*

This example shows an issue with the Arduino IDE and modified but not saved .ino files, e.g. in library path

see https://github.com/arduino/Arduino/issues/4231

1. step: compile and run unmodified from library path, see result in Serial Monitor

2. step: add a space, compile and run, see result in Serial Monitor

result: sizeof(umlauts) and codes are different.

*/
