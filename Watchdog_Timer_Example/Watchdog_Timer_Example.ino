#include "inc/hw_types.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/wdt.h"
#include "driverlib/prcm.h"
#include "inc/hw_memmap.h"

// Standard includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driverlib includes
#include "inc/hw_common_reg.h"
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"
#include "inc/hw_wdt.h"
#include "driverlib/prcm.h"
#include "driverlib/debug.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/interrupt.h"
#include "driverlib/utils.h"

#define MICROSECONDS_TO_TICKS(us) ((80000000 / 1000000) * (us))
#define SLOW_TIMER_DELAY_uS 1000000 //1 second

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(112500);
  delay(100);
  MAP_PRCMPeripheralClkEnable(PRCM_WDT, PRCM_RUN_MODE_CLK);
  WatchdogReloadSet(WDT_BASE,MICROSECONDS_TO_TICKS(SLOW_TIMER_DELAY_uS*4));
  Serial.println("Checking watchdog timer status!");
  if(MAP_WatchdogRunning(WDT_BASE)){
    Serial.println("It's on!");
  }else {
    Serial.println("It's off!");
    MAP_WatchdogEnable(WDT_BASE);
    Serial.println("enabled watchdog!");
  }
  Serial.println("Done with testing!");
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.println("done");
}
