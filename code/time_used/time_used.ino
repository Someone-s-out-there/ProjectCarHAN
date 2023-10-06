#include <LiquidCrystal_I2C.h> 
#include <EEPROM.h>
#include "userTime.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long userTimePer10;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  userTimePer10 = getUserTime();
  lcd.setCursor(0, 0);
  lcd.print(userTimePer10);
}

void loop() {
  userTimePer10 += millis() / 10000;
  updateUserTime(userTimePer10);
}
