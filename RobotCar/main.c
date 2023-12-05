/*
 * RobotCar.c
 *
 * Created: 10/23/2023 7:16:03 PM
 * Author : Sjoerd
 */

#include "Functions/Appinfo.h"
#include "Functions/Buttons/mode_select.h"
#include "Functions/millis/millis.h"
#include <avr/io.h>

int main(void) {
  IO_init();
  millis_init();

  while (1) {
    readSwitches();
  }
}
