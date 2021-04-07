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

int
main(void)
{
tContext sContext;
tRectangle sRect;

ROM_FPULazyStackingEnable();

ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

ILI9341_240x320x262K_Init();

GrContextInit(&sContext, &g_sILI9341_240x320x262K);

GrContextForegroundSet(&sContext, ClrGreen);
GrCircleFill(&sContext,160, 81, 60);

unsigned long rysuj = 0;
unsigned long kolor2 =1 ; //lewy dolny
unsigned long kolor4 =2 ;// prawy dolny

for(int i=0;i<96;i++){
GrContextForegroundSet(&sContext, ClrBlue);
GrLineDraw( &sContext , 160-(i/2), 20+rysuj, 160+(i/2), 20+rysuj);

rysuj++;
}

while(1)
{

if(kolor2 % 4 == 0 ){
GrContextForegroundSet(&sContext, ClrBlack);
GrContextFontSet(&sContext, g_psFontCmsc22);
GrStringDrawCentered(&sContext, "Niebieski", -1, 60, 170, 0);
}

if(kolor2 % 4 == 1 ){
GrContextForegroundSet(&sContext, ClrGreen);
GrContextFontSet(&sContext, g_psFontCmsc22);
GrStringDrawCentered(&sContext, "Niebieski", -1, 60, 170, 0);
}

if(kolor2 % 4 == 2 ){
GrContextForegroundSet(&sContext, ClrRed);
GrContextFontSet(&sContext, g_psFontCmsc22);
GrStringDrawCentered(&sContext, "Niebieski", -1, 60, 170, 0);
}

if(kolor2 % 4 == 3 ){
GrContextForegroundSet(&sContext, ClrBlue);
GrContextFontSet(&sContext, g_psFontCmsc22);
GrStringDrawCentered(&sContext, "Niebieski", -1, 60, 170, 0); 
}

kolor2++;

if(kolor4 % 4 == 0 ){
GrContextForegroundSet(&sContext, ClrBlack);
GrContextFontSet(&sContext, g_psFontCm22b);
GrStringDrawCentered(&sContext, "Zielony", -1, 250, 170, 0);
}

if(kolor4 % 4 == 1 ){
GrContextForegroundSet(&sContext, ClrGreen);
GrContextFontSet(&sContext, g_psFontCm22b);
GrStringDrawCentered(&sContext, "Zielony", -1, 250, 170, 0);
}

if(kolor4 % 4 == 2 ){
GrContextForegroundSet(&sContext, ClrRed);
GrContextFontSet(&sContext, g_psFontCm22b);
GrStringDrawCentered(&sContext, "Zielony", -1, 250, 170, 0);
}

if(kolor4 % 4 == 3 ){


GrContextForegroundSet(&sContext, ClrBlue);
GrContextFontSet(&sContext, g_psFontCm22b);
GrStringDrawCentered(&sContext, "Zielony", -1, 250, 170, 0); 
}

kolor4++;
ROM_SysCtlDelay(ROM_SysCtlClockGet()/2);

}
} 