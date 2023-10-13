#include "Mode_Select.h"

void setup()
{
  Serial.begin(9600);
  switchSetup();
}

void loop()
{
  readSwitches();
}