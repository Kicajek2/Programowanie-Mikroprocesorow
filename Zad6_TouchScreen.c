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

void SysTickIntHandler(void)
{
    g_ui32SysTickCount++;
}

inline bool IsInCircle(int32_t X,int32_t Y,int32_t cX,int32_t cY,int32_t radius)
{
	return ( (X-cX)*(X-cX) + (Y-cY)*(Y-cY) < (radius*radius) );
}

tRectangle sRect;

unsigned long wielkosc = 5;
unsigned long kolor = 0;
unsigned long figura = 0;
unsigned long X1 = 0 , X2=0 , X3=0 , X4=0;

int32_t TouchCallback(uint32_t ulMessage, int32_t lX, int32_t lY)
{
    if( (lX<160) && (lY<120) && (lY>0) )
    {
        X1=1;
    }
    if( (lX>160) && (lY<120) && (lY>0) )
    {
        X2=1;
    }
    if( (lX>160) && (lY<240) && (lY>120) )
    {
        X3=1;
    }
    if( (lX<160) && (lY<240) && (lY>120) )
    {
        X4=1;
    }
    if( (lX<36) && (lY<24) && (lY>0) )
    {
        X1 = 0 ;
        X2 = 0 ; 
        X3 = 0 ;
        X4 = 0 ;

        sRect.i16XMin = 36;
        sRect.i16YMin = 0;
        sRect.i16XMax = 320;
        sRect.i16YMax = 240;
        GrContextForegroundSet(&sContext, ClrWhite);
        GrRectFill(&sContext, &sRect);
    }
    
    if( (X1==1 && X4==1) && (X2==0 && X3==0) )
    {
        sRect.i16XMin = 36;
        sRect.i16YMin = 0;
        sRect.i16XMax = 320;
        sRect.i16YMax = 240;
        GrContextForegroundSet(&sContext, ClrBlue);
        GrRectFill(&sContext, &sRect);
    }
    
    if( (X1==1 && X4==0) && (X2==1 && X3==1) )
    {
        sRect.i16XMin = 36;
        sRect.i16YMin = 0;
        sRect.i16XMax = 320;
        sRect.i16YMax = 240;
        GrContextForegroundSet(&sContext, ClrRed);
        GrRectFill(&sContext, &sRect);
    }
    if( (X1==1 && X4==1) && (X2==1 && X3==0) )
    {
        sRect.i16XMin = 36;
        sRect.i16YMin = 0;
        sRect.i16XMax = 320;
        sRect.i16YMax = 240;
        GrContextForegroundSet(&sContext, ClrYellow);
        GrRectFill(&sContext, &sRect);
    }
    if( (X2==1 && X3==1) && (X1==0 && X4==0) )
    {
        sRect.i16XMin = 36;
        sRect.i16YMin = 0;
        sRect.i16XMax = 320;
        sRect.i16YMax = 240;
        GrContextForegroundSet(&sContext, ClrGreen);
        GrRectFill(&sContext, &sRect);
    }
    
    GrContextForegroundSet(&sContext, ClrRed);
    GrCircleFill(&sContext,lX, lY, wielkosc);
        


	i32CenterX = lX;
	i32CenterY = lY;
	return 0;
}



int main(void)
{

    ROM_FPULazyStackingEnable();

    ROM_SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN |
                       SYSCTL_XTAL_8MHZ);

    ILI9341_240x320x262K_Init();

    GrContextInit(&sContext, &g_sILI9341_240x320x262K);

    TouchScreenInit();
    TouchScreenCalibrate(&sContext);
    TouchScreenCallbackSet(TouchCallback);

    GrContextFontSet(&sContext, g_psFontCm12);

    while(1)
    {

    }

}
