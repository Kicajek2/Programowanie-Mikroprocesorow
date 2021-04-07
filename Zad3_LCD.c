#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/fpu.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"
#include "grlib/grlib.h"
#include "drivers/ili9341_240x320x262K.h"
#include "utils/uartstdio.h"
#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"
#define GPIO_PINS_ALL GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7

// PB0 „do góry”
// PB7 „w lewo”
// PE4 „w prawo”
// PE5 „W dół”
// PH2 „przyciśnięcie”

int main(void)
{
	tContext sContext;
	tRectangle sRect;
	ROM_FPULazyStackingEnable();
	ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
	ILI9341_240x320x262K_Init();
	GrContextInit(&sContext, &g_sILI9341_240x320x262K);
	
	unsigned long rysuj = 0;
    unsigned long X =160;
    unsigned long Y =20;

	ROM_SysCtlClockSet (SYSCTL_SYSDIV_20 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);

	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOJ);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOH);
    SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOG);

	GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE, GPIO_PIN_7);
    GPIOPinTypeGPIOInput(GPIO_PORTH_BASE, GPIO_PIN_7);
    GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_7);
    GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_0);
    GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_4);
    GPIOPinTypeGPIOInput(GPIO_PORTE_BASE, GPIO_PIN_5);
	for (;;)
	{

		while(GPIOPinRead(GPIO_PORTE_BASE,GPIO_PIN_4) == GPIO_PIN_4)
        {
            X++;
            break;
			
        }
		while(GPIOPinRead(GPIO_PORTE_BASE,GPIO_PIN_5) == GPIO_PIN_5)
        {
			Y++;
            break;
        }
        while(GPIOPinRead(GPIO_PORTB_BASE,GPIO_PIN_0) == GPIO_PIN_0)
        {
            Y--;
            break;
			
        }
        while(GPIOPinRead(GPIO_PORTB_BASE,GPIO_PIN_7) == GPIO_PIN_7)
        {
            X--;
            break;
			
        }

        sRect.i16XMin = 0;
        sRect.i16YMin = 0;
        sRect.i16XMax = 360;
        sRect.i16YMax = 240;

        ROM_SysCtlDelay(ROM_SysCtlClockGet()/20);

        GrContextForegroundSet(&sContext, ClrWhite);
        GrRectFill(&sContext, &sRect);

        

        for(int i=0;i<96;i++){
                GrContextForegroundSet(&sContext, ClrBlue);
                GrLineDraw( &sContext , X-(i/2), Y+rysuj, X+(i/2), Y+rysuj);

                rysuj++;
            }
        rysuj=0;
 
	}
	return 0;
} 