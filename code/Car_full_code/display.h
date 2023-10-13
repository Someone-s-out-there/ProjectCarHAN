#ifndef display_h
#define display_h

enum motorDirection {
  STILL = 's',
  FORWARD = 'f',
  BACKWARD = 'b',
  LEFT = 'l',
  RIGHT = 'r'
};

enum modes { MANUAL = 'm', SLAVE = 's', AUTONOMOUS = 'a', STOP = '-' };

void displaySetup();
void displayBattery(uint8_t batteryPercentage);
void displayTimeUsed(uint32_t hours, uint32_t minutes);
void displayDirection(char direction);
void displayMode(char mode);
void displaySpeed(float speed);
void batteryCycle();

#endif