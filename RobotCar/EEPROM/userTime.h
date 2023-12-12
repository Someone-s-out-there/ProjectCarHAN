/*
 * userTime.h
 *
 * Created: 12-12-2023 13:52:04
 *  Author: jspaa
 */ 


#ifndef USERTIME_H_
#define USERTIME_H_

#include "EEPROM.h"
#include "../Functions/millis/millis.h"
#include "../Display/display.h"

void getUserTime(void);

void updateUserTime(void);

#endif /* USERTIME_H_ */