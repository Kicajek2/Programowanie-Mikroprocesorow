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
	
    unsigned long X =20;
    unsigned long Y =20;
    unsigned long tab[40][30];
    unsigned long pomoc = 0;

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

        for(int i =0;i<40;i++)
        {
            for(int j=0;j<30;j++)
            {
                sRect.i16XMin = i*8;
                sRect.i16YMin = j*8;
                sRect.i16XMax = i*8 + 8;
                sRect.i16YMax = j*8 + 8;

                GrContextForegroundSet(&sContext, ClrWhite);
                GrRectFill(&sContext, &sRect); 

            }

        }

        for(int i=0;i<40;i++) /// górna linia czarna
        {
            sRect.i16XMin = pomoc;
            sRect.i16YMin = 0;
            sRect.i16XMax = pomoc+8;
            sRect.i16YMax = 8;

            GrContextForegroundSet(&sContext, ClrBlack);
            GrRectFill(&sContext, &sRect);

            pomoc=pomoc+8;
        }
        pomoc=0;

        for(int i=0;i<40;i++) // dolna linia czarna
        {
            sRect.i16XMin = pomoc;
            sRect.i16YMin = 232;
            sRect.i16XMax = pomoc+8;
            sRect.i16YMax = 240;

            GrContextForegroundSet(&sContext, ClrBlack);
            GrRectFill(&sContext, &sRect);

            pomoc=pomoc+8;
        }
        pomoc=0;

       for(int i=0;i<30;i++) //lewa linia czarna
        {
            sRect.i16XMin = 0;
            sRect.i16YMin = pomoc;
            sRect.i16XMax = 8;
            sRect.i16YMax = pomoc+8;

            GrContextForegroundSet(&sContext, ClrBlack);
            GrRectFill(&sContext, &sRect);

            pomoc=pomoc+8;
        }
        pomoc=0;

        for(int i=0;i<30;i++) //prawa linia czarna
        {
            sRect.i16XMin = 312;
            sRect.i16YMin = pomoc;
            sRect.i16XMax = 320;
            sRect.i16YMax = pomoc+8;

            GrContextForegroundSet(&sContext, ClrBlack);
            GrRectFill(&sContext, &sRect);

            pomoc=pomoc+8;
        }
        pomoc=0;

        //tab jest 40 na 30

        for(int i =0;i<40;i++){
            for(int j=0;j<30;j++){
                tab[i][j]=0;
            }
        }
        
        

        for(int i=0;i<40;i++){ // x skrajne ustawione jako sciany
            tab[i][0]=2000;
            tab[i][29]=2000;
        }

        

        for(int i=0;i<30;i++){ // y skrajne ustawione jako sciany
            tab[0][i]=2000;
            tab[39][i]=2000;
        }

        tab[20][20]=3; // lokalizacja glowy weza na start
        unsigned long dlugosc = 3; //dlugosc wynża
        unsigned long kierunek = 0; // 0 to lewo , 1 to góra , 2 to prawo , 3 dół
        unsigned long jedzenie = 12;
        unsigned long ile_do_jedzenia = 0;

	for (;;)
	{
        if(GPIOPinRead(GPIO_PORTE_BASE,GPIO_PIN_4) == GPIO_PIN_4)
        {
            if(kierunek != 0)
            {
                kierunek = 2;
            }
            
        }
		if(GPIOPinRead(GPIO_PORTE_BASE,GPIO_PIN_5) == GPIO_PIN_5)
        {
			if(kierunek != 3)
            {
                kierunek = 1;
            }
        }
        if(GPIOPinRead(GPIO_PORTB_BASE,GPIO_PIN_0) == GPIO_PIN_0)
        {
            if(kierunek != 1)
            {
                kierunek = 3;
            }
        }
        if(GPIOPinRead(GPIO_PORTB_BASE,GPIO_PIN_7) == GPIO_PIN_7)
        {
           if(kierunek != 2)
            {
                kierunek = 0;
            }
        }

        if(kierunek == 0)
        {
            X--;
        }
        if(kierunek == 1)
        {
            Y++;
        }
        if(kierunek == 2)
        {
            X++;
        }
        if(kierunek == 3)
        {
            Y--;
        }
        if( (tab[X][Y]!=0) && (tab[X][Y]!=1600) )
        {
            break;
        }
        else if(tab[X][Y]==1600)
        {
            dlugosc++;
            tab[X][Y]=dlugosc;
        }
        else
        {
        tab[X][Y]=dlugosc;
        }

        if(ile_do_jedzenia==0)
        {
            tab[ (jedzenie%37) +1][(jedzenie%27) +1]=1600;
            jedzenie= (jedzenie * 123) % 2000;
            ile_do_jedzenia=10;
        }
        ile_do_jedzenia--;


        for(int i =0;i<40;i++)
        {
            for(int j=0;j<30;j++)
            {
                
                if(tab[i][j]<1500)
                {

                    if(tab[i][j]<1)
                    {
                        
                    }
                    else
                    {
                        sRect.i16XMin = i*8;
                        sRect.i16YMin = j*8;
                        sRect.i16XMax = i*8 + 8;
                        sRect.i16YMax = j*8 + 8;

                        GrContextForegroundSet(&sContext, ClrGreen);
                        GrRectFill(&sContext, &sRect);

                        tab[i][j]--;
                        if(tab[i][j]==0)
                        {
                            sRect.i16XMin = i*8;
                            sRect.i16YMin = j*8;
                            sRect.i16XMax = i*8 + 8;
                            sRect.i16YMax = j*8 + 8;

                            GrContextForegroundSet(&sContext, ClrWhite);
                            GrRectFill(&sContext, &sRect);
                        }
                    }
                }
                if(tab[i][j]==1600)
                {
                    sRect.i16XMin = i*8;
                    sRect.i16YMin = j*8;
                    sRect.i16XMax = i*8 + 8;
                    sRect.i16YMax = j*8 + 8;

                    GrContextForegroundSet(&sContext, ClrRed);
                    GrRectFill(&sContext, &sRect);
                }

            }
            
        }
        for(int i=0;i<100000;i++)
        {
            ROM_SysCtlDelay(ROM_SysCtlClockGet()/3);
        }
        


	}
        sRect.i16XMin = 0;
        sRect.i16YMin = 0;
        sRect.i16XMax = 360;
        sRect.i16YMax = 240;

        GrContextForegroundSet(&sContext, ClrWhite);
        GrRectFill(&sContext, &sRect);

        GrContextForegroundSet(&sContext, ClrBlack);
        GrContextFontSet(&sContext, g_psFontCmsc22);
        GrStringDrawCentered(&sContext, "Game Over", -1, 160, 120, 0);
	return 0;
} 