#include <EEPROM.h>

uint32_t EEPROMSize = 1024;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < EEPROMSize; i++)
  {
    EEPROM.update(i, 0);
  }

  Serial.println("EEPROM is reset");
}

void loop()
{

}