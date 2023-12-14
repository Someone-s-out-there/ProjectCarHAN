/*
 * Voltage_monitoring.h
 *
 * Created: 14-12-2023 09:15:12
 *  Author: Julian Janssen
 */ 
#include <avr/io.h>

#ifndef VOLTAGE_MONITORING_H_
#define VOLTAGE_MONITORING_H_

void initVoltageMonitoring(void);
uint16_t getVoltage(void);
long map(long x, long in_min, long in_max, long out_min, long out_max);


#endif /* VOLTAGE_MONITORING_H_ */