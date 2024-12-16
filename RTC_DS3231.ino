/*
Electronics Studio
@file RTC_DS32s31.ino
@date  16-12-2024
@url https:https://github.com/electronicsstudio
@url YouTube: https://www.youtube.com/@ElectronicsStudio-v7o/featured
*/

#include "Arduino.h"
#include "uRTCLib.h"

// uRTCLib rtc;
uRTCLib rtc(0x68);

void setup() {
  Serial.begin(9600);

  URTCLIB_WIRE.begin();

  // Comment out below line once you set the date & time.
  // Following line sets the RTC with an explicit date & time
  // for example to set January 13 2022 at 12:56 you would call:
  //rtc.set(0,57, 12, 7, 14, 12, 24);
  // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // set day of week (1=Sunday, 7=Saturday)
}

void loop() {
  rtc.refresh();

  Serial.print("RTC Time/Date:");
  Serial.print(rtc.hour()); //HH
  Serial.print(":");
  Serial.print(rtc.minute()); //MM
  Serial.print(":");
  Serial.print(rtc.second()); //SS

  Serial.print(' ');

  Serial.print(rtc.year());
	Serial.print('/');
	Serial.print(rtc.month());
	Serial.print('/');
	Serial.print(rtc.day());

   Serial.print(' ');

  Serial.print("DOW ");
  Serial.println(rtc.dayOfWeek());

  delay(500);
}