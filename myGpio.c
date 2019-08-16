// ----------------------------------------------------------------------------
// myGpio.c  ('FR6989 Launchpad)
// ----------------------------------------------------------------------------

#include <driverlib.h>
#include "myGpio.h"


//*****************************************************************************
// Initialize GPIO
//*****************************************************************************
void initGPIO(void)
{

    // Set LFXT (low freq crystal pins) to crystal input (rather than GPIO)
    GPIO_setAsPeripheralModuleFunctionInputPin(
            GPIO_PORT_PJ,
            GPIO_PIN4 +              	// LFXIN  on PJ.4
            GPIO_PIN5 ,             	// LFXOUT on PJ.5
            GPIO_PRIMARY_MODULE_FUNCTION
    );
}
