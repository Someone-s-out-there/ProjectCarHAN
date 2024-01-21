/*
 * display.h
 *
 * Created: 12-12-2023 10:30:11
 *  Author: jspaa
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdint.h>

#include "../DriveModes/modes.h"

void displayMode(modes_t mode);
void displaySpeed(uint16_t speed);
void displayTimeUsed(uint16_t hours, uint8_t minutes);
// void displayDirection(direction_t direction);
void displayBattery(void);

#endif /* DISPLAY_H_ */
