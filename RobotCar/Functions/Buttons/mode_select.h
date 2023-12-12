/*
 * mode_select.h
 *
 * Created: 23-11-2023 11:49:56
 *  Author: jspaa
 */ 


#ifndef MODE_SELECT_H_
#define MODE_SELECT_H_

#include <avr/io.h>
#include "../Pinmap.h"
#include "../millis/millis.h"

// Include modes
#include "../../Modes/autonomous.h"
#include "../../Modes/manual.h"
#include "../../Modes/slave.h"

void readSwitches(void);
void stopMode(void);

#endif /* MODE_SELECT_H_ */