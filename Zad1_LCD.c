//*****************************************************************************
// hello.c - Simple hello world example.
//
// Maciej Kucia July 2013
//
// This is part of revision 1.0 of the EK-LM4F232 Firmware Package.
//*****************************************************************************
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
//*****************************************************************************
//
// TI logo in array form (1 bit per pixel)
//
//*****************************************************************************
//const unsigned char TI_logo[(16*2)+5] = {
//IMAGE_FMT_1BPP_UNCOMP, 16,0, 16,0,
//0x0f,0xff,0x0f,0xff,0x0f,0xf3,0x0f,0xfa,0x0f,0x8f,0x0f,0x89,0x81,0x99,0x81,0x19,0x03,0x09,0x07,//0x89,0x07,0xdf,0x3f,0xee,0x7f,0xf0,0xff,0xf8,0xff ,0xf9,0xff,0xfb}; 
// 1,1,1,1,0,0,0,0, 1,1,1,1,1,1,1,1,
// 1,1,1,1,0,0,0,0, 1,1,1,1,1,1,1,1,
// 1,1,1,1,0,0,0,0, 1,1,0,0,1,1,1,1,
// 1,1,1,1,0,0,0,0, 0,1,0,1,1,1,1,1,
// 1,1,1,1,0,0,0,0, 1,1,1,1,0,0,0,1,
// 1,1,1,1,0,0,0,0, 1,0,0,1,0,0,0,1,
// 1,0,0,0,0,0,0,1, 1,0,0,1,1,0,0,1,
// 1,0,0,0,0,0,0,1, 1,0,0,1,1,0,0,0,
// 1,1,0,0,0,0,0,0, 1,0,0,1,0,0,0,0,
// 1,1,1,0,0,0,0,0, 1,0,0,1,0,0,0,1,
// 1,1,1,0,0,0,0,0, 1,1,1,1,1,0,1,1,
// 1,1,1,1,1,1,0,0, 0,1,1,1,0,1,1,1,
// 1,1,1,1,1,1,1,0, 0,0,0,0,1,1,1,1,
// 1,1,1,1,1,1,1,1, 0,0,0,1,1,1,1,1,
// 1,1,1,1,1,1,1,1, 1,0,0,1,1,1,1,1,
// 1,1,1,1,1,1,1,1, 1,1,0,1,1,1,1,1
//*****************************************************************************
//
// Print some text to the display.
//
//***********************************************

int
main(void)
{
tContext sContext;
tRectangle sRect;
//
// Enable lazy stacking for interrupt handlers. This allows floating-point
// instructions to be used within interrupt handlers, but at the expense of
// extra stack usage.
//
ROM_FPULazyStackingEnable();
//
// Set the clocking to run directly from the crystal.
//
ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
//
// Initialize the display driver.
//
ILI9341_240x320x262K_Init();
//
// Initialize the graphics context.
//
GrContextInit(&sContext, &g_sILI9341_240x320x262K);
//
// Print some text
/*

GrContextFontSet(&sContext, g_psFontCm20b);
GrStringDrawCentered(&sContext, "EUP", -1,GrContextDpyWidthGet(&sContext) / 2,20 + (GrContextDpyHeightGet(&sContext) / 2),0);

// Draw TI logo
//
sRect.i16XMin = 0;
sRect.i16YMin = 220;
sRect.i16XMax = 319;
sRect.i16YMax = 239;
GrContextBackgroundSet(&sContext, ClrWhite);
GrContextForegroundSet(&sContext, ClrRed);
GrRectFill(&sContext, &sRect);
//GrImageDraw(&sContext, TI_logo, 200, 222);
GrContextForegroundSet(&sContext, ClrWhite);
GrContextFontSet(&sContext, g_psFontFixed6x8);
GrStringDraw(&sContext, "Texas", -1,218,222,0);
GrStringDraw(&sContext, "Instruments", -1,218,230,0);
//
// Flush any cached drawing operations.
//
GrFlush(&sContext);
//
// We are finished. Hang around doing nothing.
//*/
unsigned long ii1 = 1;
unsigned long ii2 = 1;
unsigned long ii3 = 1;
unsigned long ii4 = 1;
unsigned long kolor1 =0 ;// lewy górny
unsigned long kolor2 =1 ; //lewy dolny
unsigned long kolor3 =3 ;// prawy górny
unsigned long kolor4 =2 ;// prawy dolny
while(1)// 11111111111111111111111111 lewy górny
{
//
// Draw RGB rectangles



sRect.i16XMin = 10;
sRect.i16YMin = 10;
sRect.i16XMax = 110;
sRect.i16YMax = 110;
// unsigned long temp_color = ColorTranslate(void *pvDisplayData, ii);
ii1=ii1+0.01;
if(kolor1 % 4 == 0 ){
GrContextForegroundSet(&sContext, ClrRed);
GrRectFill(&sContext, &sRect);

GrContextForegroundSet(&sContext, ClrBlack);
GrContextFontSet(&sContext, g_psFontCm22);
GrStringDrawCentered(&sContext, "Pole A", -1, 50, 50, 0);
}

if(kolor1 % 4 == 1 ){
GrContextForegroundSet(&sContext, ClrYellow);
GrRectFill(&sContext, &sRect); 

GrContextForegroundSet(&sContext, ClrGreen);
GrContextFontSet(&sContext, g_psFontCmss22i);
GrStringDrawCentered(&sContext, "Pole B", -1, 50, 50, 0);
}

if(kolor1 % 4 == 2 ){
GrContextForegroundSet(&sContext, ClrBlue);
GrRectFill(&sContext, &sRect);

GrContextForegroundSet(&sContext, ClrRed);
GrContextFontSet(&sContext, g_psFontCmsc22);
GrStringDrawCentered(&sContext, "Pole C", -1, 50, 50, 0);
}

if(kolor1 % 4 == 3 ){
GrContextForegroundSet(&sContext, ClrGreen);
GrRectFill(&sContext, &sRect);

GrContextForegroundSet(&sContext, ClrBlue);
GrContextFontSet(&sContext, g_psFontCm22b);
GrStringDrawCentered(&sContext, "Pole D", -1, 50, 50, 0); 
}

kolor1++;

//222222222222222222222222222222222222222 lewy dolny
// Draw RGB rectangles
//
sRect.i16XMin = 10;
sRect.i16YMin = 130;
sRect.i16XMax = 110;
sRect.i16YMax = 230;

// unsigned long temp_color = ColorTranslate(void *pvDisplayData, ii);
ii2=ii2+0.01;
if(kolor2 % 4 == 0 ){
GrContextForegroundSet(&sContext, ClrRed);
GrRectFill(&sContext, &sRect);

GrContextForegroundSet(&sContext, ClrBlack);
GrContextFontSet(&sContext, g_psFontCm22);
GrStringDrawCentered(&sContext, "Pole A", -1, 50, 170, 0);
}

if(kolor2 % 4 == 1 ){
GrContextForegroundSet(&sContext, ClrYellow);
GrRectFill(&sContext, &sRect); 

GrContextForegroundSet(&sContext, ClrGreen);
GrContextFontSet(&sContext, g_psFontCmss22i);
GrStringDrawCentered(&sContext, "Pole B", -1, 50, 170, 0);
}

if(kolor2 % 4 == 2 ){
GrContextForegroundSet(&sContext, ClrBlue);
GrRectFill(&sContext, &sRect);

GrContextForegroundSet(&sContext, ClrRed);
GrContextFontSet(&sContext, g_psFontCmsc22);
GrStringDrawCentered(&sContext, "Pole C", -1, 50, 170, 0);
}

if(kolor2 % 4 == 3 ){
GrContextForegroundSet(&sContext, ClrGreen);
GrRectFill(&sContext, &sRect);

GrContextForegroundSet(&sContext, ClrBlue);
GrContextFontSet(&sContext, g_psFontCm22b);
GrStringDrawCentered(&sContext, "Pole D", -1, 50, 170, 0); 
}

kolor2++;
//////333333333333333333333333333333333333 prawy górny
//
// Draw RGB rectangles
//
sRect.i16XMin = 210;
sRect.i16YMin = 10;
sRect.i16XMax = 310;
sRect.i16YMax = 110;
// unsigned long temp_color = ColorTranslate(void *pvDisplayData, ii);
ii3=ii3+0.01;
if(kolor3 % 4 == 0 ){
GrContextForegroundSet(&sContext, ClrRed);
GrRectFill(&sContext, &sRect);

GrContextForegroundSet(&sContext, ClrBlack);
GrContextFontSet(&sContext, g_psFontCm22);
GrStringDrawCentered(&sContext, "Pole A", -1, 250, 50, 0);
}

if(kolor3 % 4 == 1 ){
GrContextForegroundSet(&sContext, ClrYellow);
GrRectFill(&sContext, &sRect); 

GrContextForegroundSet(&sContext, ClrGreen);
GrContextFontSet(&sContext, g_psFontCmss22i);
GrStringDrawCentered(&sContext, "Pole B", -1, 250, 50, 0);
}

if(kolor3 % 4 == 2 ){
GrContextForegroundSet(&sContext, ClrBlue);
GrRectFill(&sContext, &sRect);

GrContextForegroundSet(&sContext, ClrRed);
GrContextFontSet(&sContext, g_psFontCmsc22);
GrStringDrawCentered(&sContext, "Pole C", -1, 250, 50, 0);
}

if(kolor3 % 4 == 3 ){
GrContextForegroundSet(&sContext, ClrGreen);
GrRectFill(&sContext, &sRect);

GrContextForegroundSet(&sContext, ClrBlue);
GrContextFontSet(&sContext, g_psFontCm22b);
GrStringDrawCentered(&sContext, "Pole D", -1, 250, 50, 0); 
}

kolor3++;
////44444444444444444444444444444444444444 prawy dolny
//
// Draw RGB rectangles
//
sRect.i16XMin = 210;
sRect.i16YMin = 130;
sRect.i16XMax = 310;
sRect.i16YMax = 230;
// unsigned long temp_color = ColorTranslate(void *pvDisplayData, ii);
ii4=ii4+0.01;
if(kolor4 % 4 == 0 ){
GrContextForegroundSet(&sContext, ClrRed);
GrRectFill(&sContext, &sRect);

GrContextForegroundSet(&sContext, ClrBlack);
GrContextFontSet(&sContext, g_psFontCm22);
GrStringDrawCentered(&sContext, "Pole A", -1, 250, 170, 0);
}

if(kolor4 % 4 == 1 ){
GrContextForegroundSet(&sContext, ClrYellow);
GrRectFill(&sContext, &sRect); 

GrContextForegroundSet(&sContext, ClrGreen);
GrContextFontSet(&sContext, g_psFontCmss22i);
GrStringDrawCentered(&sContext, "Pole B", -1, 250, 170, 0);
}

if(kolor4 % 4 == 2 ){
GrContextForegroundSet(&sContext, ClrBlue);
GrRectFill(&sContext, &sRect);

GrContextForegroundSet(&sContext, ClrRed);
GrContextFontSet(&sContext, g_psFontCmsc22);
GrStringDrawCentered(&sContext, "Pole C", -1, 250, 170, 0);
}

if(kolor4 % 4 == 3 ){
GrContextForegroundSet(&sContext, ClrGreen);
GrRectFill(&sContext, &sRect);

GrContextForegroundSet(&sContext, ClrBlue);
GrContextFontSet(&sContext, g_psFontCm22b);
GrStringDrawCentered(&sContext, "Pole D", -1, 250, 170, 0); 
}

kolor4++;
ROM_SysCtlDelay(ROM_SysCtlClockGet()/2);


}
} 