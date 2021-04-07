/*
main.c
*/
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#define GPIO_PINS_ALL GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7

uint8_t steruj_sz = 0;// 0 to idzie w prawo  1 to idize w lewo
uint8_t steruj_w = 0;// 0 to idzie do góry   1 to idzie na dół
uint8_t szerokosc = 0;
uint8_t wysokosc = 0;

uint8_t a_l = 0;
uint8_t a_p = 0;
uint8_t b_l = 0;
uint8_t b_p = 0;
uint8_t c_l = 0;
uint8_t c_p = 0;
uint8_t d_l = 0;
uint8_t d_p = 0;
uint8_t e_l = 0;
uint8_t e_p = 0;
uint8_t f_l = 0;
uint8_t f_p = 0;
uint8_t g_l = 0;
uint8_t g_p = 0;
uint8_t h_l = 0;
uint8_t h_p = 0;
uint8_t j_l = 0;
uint8_t j_p = 0;


int main(void)
{
	
	//
	// Set the clocking to run directly from the crystal.
	//
	ROM_SysCtlClockSet (SYSCTL_SYSDIV_20 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);
	//
	// Enable GPIOA, GPIOJ, GPIOC
	//
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOC);
    SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOJ);
	SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOH);
    SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOF);
    SysCtlPeripheralEnable (SYSCTL_PERIPH_GPIOG);
	//
	// Set all GPIOA and GPIOC pins as outputs
	//	
	GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PINS_ALL);
	GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PINS_ALL);
	//
	// Set all GPIOJ pins as inputs
	//
	GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE, GPIO_PIN_7);
    GPIOPinTypeGPIOInput(GPIO_PORTH_BASE, GPIO_PIN_7);
	for (;;)
	{
		//
		// Check button press and write data to port
		
		while(GPIOPinRead(GPIO_PORTJ_BASE,GPIO_PIN_7) == GPIO_PIN_7)
        {
			
			if(steruj_sz==1)
			{
				steruj_sz=0;
                break;
			}
            if(steruj_sz==0)
			{
				steruj_sz=1;
                break;
			}
            
        }

        if(szerokosc==0)
        {
			if(wysokosc==0)
			{
				a_l =a_l + 16; //
			}
			
			if(wysokosc==1)
			{
				a_l =a_l + 32; //
			}
			
			if(wysokosc==2)
			{
				a_l =a_l + 64; //
			}
			
			if(wysokosc==3)
			{
				a_l =a_l + 128; //
			}
            
        }
        if(szerokosc==1)
        {
			if(wysokosc==0)
			{
				a_p =a_p + 1; //
			}
			
			if(wysokosc==1)
			{
				a_p =a_p + 2; //
			}
			
			if(wysokosc==2)
			{
				a_p =a_p + 4; //
			}
			
			if(wysokosc==3)
			{
				a_p =a_p + 8; //
			}
        }
        if(szerokosc==2)
        {
            if(wysokosc==0)
			{
				b_l =b_l + 16; //
			}
			
			if(wysokosc==1)
			{
				b_l =b_l + 32; //
			}
			
			if(wysokosc==2)
			{
				b_l =b_l + 64; //
			}
			
			if(wysokosc==3)
			{
				b_l =b_l + 128; //
			}
        }
        if(szerokosc==3)
        {
            if(wysokosc==0)
			{
				b_p =b_p + 1; //
			}
			
			if(wysokosc==1)
			{
				b_p =b_p + 2; //
			}
			
			if(wysokosc==2)
			{
				b_p =b_p + 4; //
			}
			
			if(wysokosc==3)
			{
				b_p =b_p + 8; //
			}
        }
        if(szerokosc==4)
        {
            if(wysokosc==0)
			{
				c_l =c_l + 16; //
			}
			
			if(wysokosc==1)
			{
				c_l =c_l + 32; //
			}
			
			if(wysokosc==2)
			{
				c_l =c_l + 64; //
			}
			
			if(wysokosc==3)
			{
				c_l =c_l + 128; //
			}
        }
        if(szerokosc==5)
        {
            if(wysokosc==0)
			{
				c_p =c_p + 1; //
			}
			
			if(wysokosc==1)
			{
				c_p =c_p + 2; //
			}
			
			if(wysokosc==2)
			{
				c_p =c_p + 4; //
			}
			
			if(wysokosc==3)
			{
				c_p =c_p + 8; //
			}
        }
        if(szerokosc==6)
        {
            if(wysokosc==0)
			{
				d_l =d_l + 16; //
			}
			
			if(wysokosc==1)
			{
				d_l =d_l +32; //
			}
			
			if(wysokosc==2)
			{
				d_l =d_l + 64; //
			}
			
			if(wysokosc==3)
			{
				d_l =d_l + 128; //
			}
        }
        if(szerokosc==7)
        {
            if(wysokosc==0)
			{
				d_p =d_p + 1; //
			}
			
			if(wysokosc==1)
			{
				d_p =d_p + 2; //
			}
			
			if(wysokosc==2)
			{
				d_p =d_p + 4; //
			}
			
			if(wysokosc==3)
			{
				d_p =d_p + 8; //
			}
        }
        if(szerokosc==8)
        {
            if(wysokosc==0)
			{
				e_l =e_l + 16; //
			}
			
			if(wysokosc==1)
			{
				e_l =e_l + 32; //
			}
			
			if(wysokosc==2)
			{
				e_l =e_l + 64; //
			}
			
			if(wysokosc==3)
			{
				e_l =e_l + 128; //
			}
        }
        if(szerokosc==9)
        {
            if(wysokosc==0)
			{
				e_p =e_p + 1; //
			}
			
			if(wysokosc==1)
			{
				e_p =e_p + 2; //
			}
			
			if(wysokosc==2)
			{
				e_p =e_p + 4; //
			}
			
			if(wysokosc==3)
			{
				e_p =e_p + 8; //
			}
        }
		if(szerokosc==10)
        {
            if(wysokosc==0)
			{
				f_l =f_l + 16; //
			}
			
			if(wysokosc==1)
			{
				f_l =f_l + 32; //
			}
			
			if(wysokosc==2)
			{
				f_l =f_l + 64; //
			}
			
			if(wysokosc==3)
			{
				f_l =f_l + 128; //
			}
        }
        if(szerokosc==11)
        {
            if(wysokosc==0)
			{
				f_p =f_p + 1; //
			}
			
			if(wysokosc==1)
			{
				f_p =f_p + 2; //
			}
			
			if(wysokosc==2)
			{
				f_p =f_p + 4; //
			}
			
			if(wysokosc==3)
			{
				f_p =f_p + 8; //
			}
        }
        if(szerokosc==12)
        {
            if(wysokosc==0)
			{
				g_l =g_l + 16; //
			}
			
			if(wysokosc==1)
			{
				g_l =g_l + 32; //
			}
			
			if(wysokosc==2)
			{
				g_l =g_l + 64; //
			}
			
			if(wysokosc==3)
			{
				g_l =g_l + 128; //
			}
        }
        if(szerokosc==13)
        {
            if(wysokosc==0)
			{
				g_p =g_p + 1; //
			}
			
			if(wysokosc==1)
			{
				g_p =g_p + 2; //
			}
			
			if(wysokosc==2)
			{
				g_p =g_p + 4; //
			}
			
			if(wysokosc==3)
			{
				g_p =g_p + 8; //
			}
        }
        if(szerokosc==14)
        {
            if(wysokosc==0)
			{
				h_l =h_l + 16; //
			}
			
			if(wysokosc==1)
			{
				h_l =h_l + 32; //
			}
			
			if(wysokosc==2)
			{
				h_l =h_l + 64; //
			}
			
			if(wysokosc==3)
			{
				h_l =h_l + 128; //
			}
        }
        if(szerokosc==15)
        {
            if(wysokosc==0)
			{
				h_p =h_p + 1; //
			}
			
			if(wysokosc==1)
			{
				h_p =h_p + 2; //
			}
			
			if(wysokosc==2)
			{
				h_p =h_p + 4; //
			}
			
			if(wysokosc==3)
			{
				h_p =h_p + 8; //
			}
        }
        if(szerokosc==16)
        {
            if(wysokosc==0)
			{
				j_l = j_l + 16; //
			}
			
			if(wysokosc==1)
			{
				j_l = j_l + 32; //
			}
			
			if(wysokosc==2)
			{
				j_l = j_l + 64; //
			}
			
			if(wysokosc==3)
			{
				j_l = j_l + 128; //
			}
        }
        if(szerokosc==17)
        {
            if(wysokosc==0)
			{
				j_p = j_p + 1; //
			}
			
			if(wysokosc==1)
			{
				j_p = j_p + 2; //
			}
			
			if(wysokosc==2)
			{
				j_p = j_p + 4; //
			}
			
			if(wysokosc==3)
			{
				j_p = j_p + 8; //
			}
        }
		if(szerokosc==0)
		{
			steruj_sz=0;
		}
		
		if(szerokosc==17)
		{
			steruj_sz=1;
		}
		
		if(steruj_sz==0)
			{
				szerokosc++;
			}
			
		if(steruj_sz==1)
			{
				szerokosc--;
			}
		
		if(wysokosc==3)
		{
			steruj_w=1;
		}
		
		if(wysokosc==0)
		{
			steruj_w=0;
		}
		
		if(steruj_w==0)
			{
				wysokosc++;
			}
		
		if(steruj_w==1)
			{
				wysokosc--;
			}

		// Show some patterns on LEDs
		//
		GPIOPinWrite (GPIO_PORTA_BASE, 0xFF, a_l+a_p);
        GPIOPinWrite (GPIO_PORTB_BASE, 0xFF, b_l+b_p);
        GPIOPinWrite (GPIO_PORTC_BASE, 0xFF, c_l+c_p);
        GPIOPinWrite (GPIO_PORTD_BASE, 0xFF, d_l+d_p);
        GPIOPinWrite (GPIO_PORTE_BASE, 0xFF, e_l+e_p);
        GPIOPinWrite (GPIO_PORTF_BASE, 0xFF, f_l+f_p);
        GPIOPinWrite (GPIO_PORTG_BASE, 0xFF, g_l+g_p);
        GPIOPinWrite (GPIO_PORTH_BASE, 0xFF, h_l+h_p);
        GPIOPinWrite (GPIO_PORTJ_BASE, 0xFF, j_l+j_p);
		
		// Delay for a while so changes can be visible
		//
		SysCtlDelay(SysCtlClockGet() / 2);
	}
	return 0;
} 