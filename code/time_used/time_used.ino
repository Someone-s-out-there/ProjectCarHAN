#include <LiquidCrystal_I2C.h> 
#include <EEPROM.h>
#include "userTime.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  getUserTime();
}

void loop() {
  updateUserTime();
}
