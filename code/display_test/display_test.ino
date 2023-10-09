#include <LiquidCrystal_I2C.h> 
#include "display.h"
#include "userTime.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

uint8_t batteryPercentage = 0;

uint32_t previousMillis = 0;
uint16_t interval = 500;

enum motorDirection
{
  STILL = 's',
  FORWARD = 'f',
  BACKWARD = 'b',
  LEFT = 'l',
  RIGHT = 'r'
};

void setup() {
  lcd.init();
  displaySetup();
  lcd.backlight();
  lcd.clear();

  displayDirection(STILL);

  getUserTime();
}

void loop() {
  uint32_t currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

    displayBattery(batteryPercentage);
    batteryPercentage += 10;

    if (batteryPercentage > 100)
    {
      batteryPercentage = 0;
    }
  }

  updateUserTime();
}
