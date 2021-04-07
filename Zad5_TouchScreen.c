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

int32_t TouchCallback(uint32_t ulMessage, int32_t lX, int32_t lY)
{
    sRect.i16XMin = 0;
    sRect.i16YMin = 0;
    sRect.i16XMax = 36;
    sRect.i16YMax = 24;
    GrContextForegroundSet(&sContext, ClrRed);
    GrRectFill(&sContext, &sRect);

    sRect.i16XMin = 0;
    sRect.i16YMin = 24;
    sRect.i16XMax = 36;
    sRect.i16YMax = 48;
    GrContextForegroundSet(&sContext, ClrBlue);
    GrRectFill(&sContext, &sRect);

    sRect.i16XMin = 0;
    sRect.i16YMin = 48;
    sRect.i16XMax = 36;
    sRect.i16YMax = 72;
    GrContextForegroundSet(&sContext, ClrYellow);
    GrRectFill(&sContext, &sRect);

    sRect.i16XMin = 0;
    sRect.i16YMin = 72;
    sRect.i16XMax = 36;
    sRect.i16YMax = 96;
    GrContextForegroundSet(&sContext, ClrGreen);
    GrRectFill(&sContext, &sRect);

    sRect.i16XMin = 0;
    sRect.i16YMin = 96;
    sRect.i16XMax = 36;
    sRect.i16YMax = 120;
    GrContextForegroundSet(&sContext, ClrBlack);
    GrRectFill(&sContext, &sRect);

    sRect.i16XMin = 0;
    sRect.i16YMin = 120;
    sRect.i16XMax = 36;
    sRect.i16YMax = 144;
    GrContextForegroundSet(&sContext, ClrYellow);
    GrRectFill(&sContext, &sRect);

    sRect.i16XMin = 0;
    sRect.i16YMin = 144;
    sRect.i16XMax = 36;
    sRect.i16YMax = 168;
    GrContextForegroundSet(&sContext, ClrGreen);
    GrRectFill(&sContext, &sRect);

    sRect.i16XMin = 0;
    sRect.i16YMin = 168;
    sRect.i16XMax = 36;
    sRect.i16YMax = 192;
    GrContextForegroundSet(&sContext, ClrRed);
    GrRectFill(&sContext, &sRect);

    sRect.i16XMin = 0;
    sRect.i16YMin = 192;
    sRect.i16XMax = 36;
    sRect.i16YMax = 216;
    GrContextForegroundSet(&sContext, ClrBlack);
    GrRectFill(&sContext, &sRect);

    sRect.i16XMin = 0;
    sRect.i16YMin = 216;
    sRect.i16XMax = 36;
    sRect.i16YMax = 240;
    GrContextForegroundSet(&sContext, ClrWhite);
    GrRectFill(&sContext, &sRect);

    if( (lX<36) && (lY<24) && (lY>0) )
    {
        kolor=0;
    }
    
    if( (lX<36) && (lY<48) && (lY>24) )
    {
        kolor=1;
    }
    if( (lX<36) && (lY<72) && (lY>48) )
    {
        kolor=2;
    }
    if( (lX<36) && (lY<96) && (lY>72) )
    {
        kolor=3;
    }
    if( (lX<36) && (lY<120) && (lY>96) )
    {
        kolor=4;
    }
    if( (lX<36) && (lY<144) && (lY>120) )
    {
        wielkosc++;
    }
    if( (lX<36) && (lY<168) && (lY>144) )
    {
        wielkosc--;
    }
    if( (lX<36) && (lY<192) && (lY>168) )
    {
        figura=0;
    }
    if( (lX<36) && (lY<216) && (lY>192) )
    {
        figura=1;
    }
    if( (lX<36) && (lY<240) && (lY>216) )
    {
        sRect.i16XMin = 36;
        sRect.i16YMin = 0;
        sRect.i16XMax = 320;
        sRect.i16YMax = 240;
        GrContextForegroundSet(&sContext, ClrWhite);
        GrRectFill(&sContext, &sRect);
    }
    if(figura==0)
    {
        if(kolor==0)
        {
            GrContextForegroundSet(&sContext, ClrRed);
            GrCircleFill(&sContext,lX, lY, wielkosc);
        }
        if(kolor==1)
        {
            GrContextForegroundSet(&sContext, ClrBlue);
            GrCircleFill(&sContext,lX, lY, wielkosc);
        }
        if(kolor==2)
        {
            GrContextForegroundSet(&sContext, ClrYellow);
            GrCircleFill(&sContext,lX, lY, wielkosc);
        }
        if(kolor==3)
        {
            GrContextForegroundSet(&sContext, ClrGreen);
            GrCircleFill(&sContext,lX, lY, wielkosc);
        }
        if(kolor==4)
        {
            GrContextForegroundSet(&sContext, ClrBlack);
            GrCircleFill(&sContext,lX, lY, wielkosc);
        }
    }

    if(figura==1)
    {
        if(kolor==0)
        {
            GrContextForegroundSet(&sContext, ClrRed);
            GrLineDraw( &sContext , lX, lY, lX+wielkosc, lY+wielkosc);
        }
        if(kolor==1)
        {
            GrContextForegroundSet(&sContext, ClrBlue);
            GrLineDraw( &sContext , lX, lY, lX+wielkosc, lY+wielkosc);
        }
        if(kolor==2)
        {
            GrContextForegroundSet(&sContext, ClrYellow);
            GrLineDraw( &sContext , lX, lY, lX+wielkosc, lY+wielkosc);
        }
        if(kolor==3)
        {
            GrContextForegroundSet(&sContext, ClrGreen);
            GrLineDraw( &sContext , lX, lY, lX+wielkosc, lY+wielkosc);
        }
        if(kolor==4)
        {
            GrContextForegroundSet(&sContext, ClrBlack);
            GrLineDraw( &sContext , lX, lY, lX+wielkosc, lY+wielkosc);
        }
    }



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
