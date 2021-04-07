#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "inc/hw_memmap.h" 
#include "driverlib/fpu.h" 
#include "driverlib/sysctl.h" 
#include "driverlib/rom.h"		
#include "driverlib/pin_map.h" 
#include "driverlib/uart.h" 	
#include "grlib/grlib.h"	
#include "drivers/ili9341_240x320x262K.h" 
#include "utils/uartstdio.h"		//Prototypes for the UART console functions.
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "drivers/touch.h"



#define GPIO_PINS_ALL GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7

volatile uint32_t g_ui32SysTickCount;



int_fast32_t i32CenterX, i32CenterY;
//int i32CenterX_temp = 100;
//int i32CenterY_temp = 100;
tContext sContext;

//*****************************************************************************
//
// This is the interrupt handler for the SysTick interrupt.  It is used to
// update our local tick count which, in turn, is used to check for transmit
// timeouts.
//
//*****************************************************************************
void
SysTickIntHandler(void)
{
    g_ui32SysTickCount++;
}


//*****************************************************************************
//
//! Callback for calibration process
//!
//! \param X - x coordinate of point to check
//! \param Y - y coordinate of point to check
//! \param cX - x coordinate of circle center
//! \param cY - y coordinate of circle center
//! \param radius - circle radius
//!
//! \return boolean true if coordinates are within circle
//
//*****************************************************************************
inline bool IsInCircle(int32_t X,int32_t Y,int32_t cX,int32_t cY,int32_t radius)
{
	return ( (X-cX)*(X-cX) + (Y-cY)*(Y-cY) < (radius*radius) );
}

tRectangle sRect;

//*****************************************************************************
//
//! Callback for calibration process
//!
//! \param ulMessage is type of event
//! \param lX is a x location of touch
//! \param lY is a y location of cross center
//!
//! \return None.
//
//*****************************************************************************

int32_t TouchCallback(uint32_t ulMessage, int32_t lX, int32_t lY)
{
    int pomoc_X =0;
    int pomoc_Y =0;
    sRect.i16XMin = 0;
    sRect.i16YMin = 0;
    sRect.i16XMax = 360;
    sRect.i16YMax = 240;

    GrContextForegroundSet(&sContext, ClrWhite);
    GrRectFill(&sContext, &sRect);

	char fullText[30];

        pomoc_X= (lX*2264)/320;
   
        pomoc_Y= (lY*1698)/240;;

	GrContextForegroundSet(&sContext, ClrGreen);
	sprintf(fullText,"Pressed (cale/1000) %d %d",pomoc_X, pomoc_Y);

	i32CenterX = lX;
	i32CenterY = lY;

	GrStringDrawCentered(&sContext, fullText, -1, lX, lY, 0);
	return 0;
}



int
main(void)
{

    //
    //
    // Enable lazy stacking for interrupt handlers.  This allows floating-point
    // instructions to be used within interrupt handlers, but at the expense of
    // extra stack usage.
    //
    ROM_FPULazyStackingEnable();

    //
    // Set the clocking to run directly from the crystal.
    //
//    ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |
//                       SYSCTL_OSC_MAIN);

    ROM_SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |
                       SYSCTL_XTAL_8MHZ);

    //
    // Initialize the display driver.
    //
    ILI9341_240x320x262K_Init();

    //
    // Initialize the graphics context.
    //
    GrContextInit(&sContext, &g_sILI9341_240x320x262K);

    //
    // Initialize touchscreen driver
    //
    TouchScreenInit();
    TouchScreenCalibrate(&sContext);
    TouchScreenCallbackSet(TouchCallback);

    

    GrContextFontSet(&sContext, g_psFontCm12);

    while(1)
    {

    }

}
