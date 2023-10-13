#include "display.h"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;

struct chars {
  byte batteryRightHigh[8] = {B11110, B00010, B11011, B11001,
                              B11001, B11011, B00010, B11110};
  byte batteryRightLow[8] = {B11110, B00010, B00011, B00001,
                             B00001, B00011, B00010, B11110};
  byte batteryMiddleHigh[8] = {B11111, B00000, B11111, B11111,
                               B11111, B11111, B00000, B11111};
  byte batteryMiddleLow[8] = {B11111, B00000, B00000, B00000,
                              B00000, B00000, B00000, B11111};
  byte batteryLeftHigh[8] = {B11111, B10000, B10111, B10111,
                             B10111, B10111, B10000, B11111};
  byte batteryLeftLow[8] = {B11111, B10000, B10000, B10000,
                            B10000, B10000, B10000, B11111};

  byte play[8] = {B00000, B11000, B11100, B11110,
                  B11110, B11100, B11000, B00000};

  byte pause[8] = {B00000, B11011, B11011, B11011,
                   B11011, B11011, B11011, B00000};

} chars;

void displaySetup() {
  lcd.createChar(0, chars.batteryLeftLow);
  lcd.createChar(1, chars.batteryLeftHigh);
  lcd.createChar(2, chars.batteryMiddleLow);
  lcd.createChar(3, chars.batteryMiddleHigh);
  lcd.createChar(4, chars.batteryRightLow);
  lcd.createChar(5, chars.batteryRightHigh);
  lcd.createChar(6, chars.play);
  lcd.createChar(7, chars.pause);
}

uint32_t previousMillis = 0;
uint16_t interval = 500;
uint8_t batteryPercentage = 0;

void batteryCycle() {
  uint32_t currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    displayBattery(batteryPercentage);
    batteryPercentage += 10;

    if (batteryPercentage > 100) {
      batteryPercentage = 0;
    }
  }
}

void displayBattery(uint8_t batteryPercentage) {
  if (batteryPercentage > 80) {
    lcd.setCursor(12, 1);
    lcd.write(byte(1));

    lcd.setCursor(13, 1);
    lcd.write(byte(3));

    lcd.setCursor(14, 1);
    lcd.write(byte(3));

    lcd.setCursor(15, 1);
    lcd.write(byte(5));
  }

  else if (batteryPercentage > 60) {
    lcd.setCursor(12, 1);
    lcd.write(byte(1));

    lcd.setCursor(13, 1);
    lcd.write(byte(3));

    lcd.setCursor(14, 1);
    lcd.write(byte(3));

    lcd.setCursor(15, 1);
    lcd.write(byte(4));
  }

  else if (batteryPercentage > 40) {
    lcd.setCursor(12, 1);
    lcd.write(byte(1));

    lcd.setCursor(13, 1);
    lcd.write(byte(3));

    lcd.setCursor(14, 1);
    lcd.write(byte(2));

    lcd.setCursor(15, 1);
    lcd.write(byte(4));
  }

  else if (batteryPercentage > 20) {
    lcd.setCursor(12, 1);
    lcd.write(byte(1));

    lcd.setCursor(13, 1);
    lcd.write(byte(2));

    lcd.setCursor(14, 1);
    lcd.write(byte(2));

    lcd.setCursor(15, 1);
    lcd.write(byte(4));
  }

  else {
    lcd.setCursor(12, 1);
    lcd.write(byte(0));

    lcd.setCursor(13, 1);
    lcd.write(byte(2));

    lcd.setCursor(14, 1);
    lcd.write(byte(2));

    lcd.setCursor(15, 1);
    lcd.write(byte(4));
  }
}

uint32_t currentModeMillis;
uint32_t previousModeMillis;
uint16_t modeInterval = 3000;
bool display_speed = false;
bool speedWillShow = false;
bool speedUpdate = false;

void displayMode(char mode) {
  display_speed = false;
  previousModeMillis = millis();
  Serial.println(previousModeMillis);

  switch (mode) {
  case 'm':
    lcd.setCursor(0, 0);
    lcd.write(byte(6));
    lcd.print("Manual   ");

    speedWillShow = true;
    speedUpdate = true;
    break;
  case 's':
    lcd.setCursor(0, 0);
    lcd.write(byte(6));
    lcd.print("Slave    ");

    speedWillShow = true;
    speedUpdate = true;
    break;
  case 'a':
    lcd.setCursor(0, 0);
    lcd.write(byte(6));
    lcd.print("Auto     ");

    speedWillShow = true;
    speedUpdate = true;
    break;
  case '-':
    lcd.setCursor(0, 0);
    lcd.write(byte(7));
    lcd.print("         ");

    speedWillShow = false;
    break;
  default:
    lcd.setCursor(0, 0);
    lcd.write(byte(7));
    lcd.print("Error    ");

    speedWillShow = false;
    break;
  }
}

float previousSpeed = 1000.0;

void displaySpeed(float speed) {
  currentModeMillis = millis();

  if (currentModeMillis - previousModeMillis >= modeInterval &&
      speedWillShow == true) {
    display_speed = true;
  }

  if (display_speed == true) {
    if (speedUpdate || previousSpeed != speed) {
      lcd.setCursor(1, 0);
      lcd.print("      ");

      lcd.setCursor(1, 0);
      lcd.print(String(speed) + " km/h");

      speedUpdate = false;
      previousSpeed = speed;
    }
  }
}

void displayTimeUsed(uint32_t hours, uint32_t minutes) {
  lcd.setCursor(0, 1);

  // Clears the time space before displaying the time
  lcd.print("         ");

  lcd.setCursor(0, 1);
  lcd.print(String(hours) + String("h ") + String(minutes) + String("m"));
}

void displayDirection(char direction) {
  switch (direction) {
  case 's':
    lcd.setCursor(8, 0);
    lcd.print("   STILL");
    break;

  case 'f':
    lcd.setCursor(8, 0);
    lcd.print(" FORWARD");
    break;

  case 'b':
    lcd.setCursor(8, 0);
    lcd.print("BACKWARD");
    break;

  case 'l':
    lcd.setCursor(8, 0);
    lcd.print("    LEFT");
    break;

  case 'r':
    lcd.setCursor(8, 0);
    lcd.print("   RIGHT");
    break;

  default:
    lcd.setCursor(8, 0);
    lcd.print("   ERROR");
    break;
  }
}