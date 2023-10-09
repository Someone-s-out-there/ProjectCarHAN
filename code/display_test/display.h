#ifndef display_h
#define display_h

void displaySetup();
void displayBattery(uint8_t batteryPercentage);
void displayTimeUsed(uint32_t hours, uint32_t minutes);
void displayDirection(char direction);
void displayMode(char mode);
void batteryCycle();

#endif