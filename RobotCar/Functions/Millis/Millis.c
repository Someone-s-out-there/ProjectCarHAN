/*
 * CFile1.c
 *
 * Created: 7-11-2023 12:15:08
 *  Author: Joep Spaanjaars
 */ 

#include "Millis.h"
#include <time.h>

unsigned long millis()
{
	clock_t runTimeInMS = clock() / (CLOCKS_PER_SEC / 1000);
	
	return runTimeInMS;
}
