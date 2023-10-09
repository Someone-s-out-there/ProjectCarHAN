#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "display.h"

extern LiquidCrystal_I2C lcd;

enum motorDirection
{
  STILL = 's',
  FORWARD = 'f',
  BACKWARD = 'b',
  LEFT = 'l',
  RIGHT = 'r'
};

struct chars
{
  byte batteryRightHigh[8] = 
  {
    B11110, 
    B00010, 
    B11011, 
    B11001, 
    B11001, 
    B11011, 
    B00010, 
    B11110
  };
  byte batteryRightLow[8] = 
  {
    B11110, 
    B00010, 
    B00011, 
    B00001, 
    B00001, 
    B00011, 
    B00010, 
    B11110
  };
  byte batteryMiddleHigh[8] = 
  {
    B11111, 
    B00000, 
    B11111,
    B11111, 
    B11111, 
    B11111, 
    B00000, 
    B11111
  };
  byte batteryMiddleLow[8] = 
  {
    B11111, 
    B00000, 
    B00000, 
    B00000, 
    B00000, 
    B00000, 
    B00000, 
    B11111
  };
  byte batteryLeftHigh[8] = 
  {
    B11111, 
    B10000, 
    B10111, 
    B10111, 
    B10111, 
    B10111, 
    B10000, 
    B11111
  };
  byte batteryLeftLow[8] = 
  {
    B11111, 
    B10000, 
    B10000, 
    B10000, 
    B10000, 
    B10000, 
    B10000, 
    B11111
  };
}chars;

void displaySetup()
{
  lcd.createChar(0, chars.batteryLeftLow);
  lcd.createChar(1, chars.batteryLeftHigh);
  lcd.createChar(2, chars.batteryMiddleLow);
  lcd.createChar(3, chars.batteryMiddleHigh);
  lcd.createChar(4, chars.batteryRightLow);
  lcd.createChar(5, chars.batteryRightHigh);
}

void displayBattery(uint8_t batteryPercentage)
{
  if (batteryPercentage > 80)
  {
    lcd.setCursor(12, 1);
    lcd.write(byte(1));

    lcd.setCursor(13, 1);
    lcd.write(byte(3));

    lcd.setCursor(14, 1);
    lcd.write(byte(3));

    lcd.setCursor(15, 1);
    lcd.write(byte(5));
  }

  else if (batteryPercentage > 60)
  {
    lcd.setCursor(12, 1);
    lcd.write(byte(1));

    lcd.setCursor(13, 1);
    lcd.write(byte(3));

    lcd.setCursor(14, 1);
    lcd.write(byte(3));

    lcd.setCursor(15, 1);
    lcd.write(byte(4));
  }

  else if (batteryPercentage > 40)
  {
    lcd.setCursor(12, 1);
    lcd.write(byte(1));

    lcd.setCursor(13, 1);
    lcd.write(byte(3));

    lcd.setCursor(14, 1);
    lcd.write(byte(2));

    lcd.setCursor(15, 1);
    lcd.write(byte(4));
  }

  else if (batteryPercentage > 20)
  {
    lcd.setCursor(12, 1);
    lcd.write(byte(1));

    lcd.setCursor(13, 1);
    lcd.write(byte(2));

    lcd.setCursor(14, 1);
    lcd.write(byte(2));

    lcd.setCursor(15, 1);
    lcd.write(byte(4));
  } 

  else
  {
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

void displayTimeUsed(uint32_t hours, uint32_t minutes)
{
  lcd.setCursor(0, 1);
  lcd.print(String(hours) + String("h ") + String(minutes) + String("m"));
}

// displaySpeed(int measuredSpeed)
// {
  
// }

void displayDirection(char direction)
{
  switch(direction)
  {
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