#include <LiquidCrystal_I2C.h> 
#include "display.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

uint8_t batteryPercentage = 0;
uint8_t timeUsed = 10;

void setup() {
  lcd.init();
  displaySetup();
  lcd.backlight();
  lcd.clear();

  //displayTimeUsed(timeUsed);

  // displayBattery(10);
}

void loop() {
  lcd.clear();
  displayBattery(batteryPercentage);
  batteryPercentage += 10;
  delay(500);

  if (batteryPercentage > 100)
  {
    batteryPercentage = 0;
  }
}
