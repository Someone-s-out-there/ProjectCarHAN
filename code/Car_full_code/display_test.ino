#include "Mode_Select.h"
#include "display.h"
#include "userTime.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  switchSetup();

  lcd.init();
  displaySetup();
  lcd.backlight();
  lcd.clear();

  displayDirection(STILL);

  displayMode(STOP);

  getUserTime();
}

void loop() {
  displaySpeed(0.0);

  // updateUserTime();

  batteryCycle();

  readSwitches();
}
