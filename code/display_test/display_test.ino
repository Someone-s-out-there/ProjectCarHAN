#include <LiquidCrystal_I2C.h> 
#include "display.h"
#include "userTime.h"
#include "Mode_Select.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

enum motorDirection
{
  STILL = 's',
  FORWARD = 'f',
  BACKWARD = 'b',
  LEFT = 'l',
  RIGHT = 'r'
};

void setup() {
  Serial.begin(9600);
  switchSetup();

  lcd.init();
  displaySetup();
  lcd.backlight();
  lcd.clear();

  displayDirection(STILL);

  getUserTime();
}

void loop() {
  updateUserTime();

  batteryCycle();

  readSwitches();
}
