#include <lpc214x.h>
#include "LPC2148_delay.h"
#include "LPC2148_LCD_4_BIT_HEADER_FILE.h"

#define ROW1	1	//O/P OF P1.16
#define ROW2	1	//O/P OF P1.17
#define ROW3	1	//O/P OF P1.18
#define ROW4	1	//O/P OF P1.19

#define COL1	0	//I/P OF P1.20
#define COL2	0	//I/P OF P1.21
#define COL3	0	//I/P OF P1.22
#define COL4	0	//I/P OF P1.23

int VALUE;

void divider(int x)
{
	int Temp,Dig1,Dig2;
	
	Temp = x;

	Dig1 = Temp/10;
	Lcd_Data(Dig1+48);

	Dig2 = Temp%10;
	Lcd_Data(Dig2+48);
}

char keypad[4][4] = {{'1', '2', '3', '+'}, 
                     {'4', '5', '6', '-'}, 
                     {'7', '8', '9', '*'}, 
                     {'.', '0', '=', '/'}};

int col,row;
										 
int main()
{
	PINSEL0 = 0x00000000;
	PINSEL2 = 0x00000000;
	
	IODIR0 = 0x0000F0FC;//00000000000000000000000011111100;
//	IODIR1 = 0x000F0000;//00000000000011110000000000000000;

	Lcd_Intialization();

	Lcd_Command(0x80);
	Lcd_String("LYCA SOFT");

	while(1)
	{
		if(IOPIN0 == 0x00001000)
		{
			if(IOPIN0 == 0x00000100)
			{
				Lcd_Command(0XC0);
				Lcd_String("LYCA SOFT");
			}
			
			if(IOPIN0 == 0x00000200)
			{
				Lcd_Command(0XC0);
				Lcd_String("LYCA SOFT");
			}
			
			if(IOPIN0 == 0x00000400)
			{
				Lcd_Command(0XC0);
				Lcd_String("LYCA SOFT");
			}
			
			if(IOPIN0 == 0x00000800)
			{
				Lcd_Command(0XC0);
				Lcd_String("LYCA SOFT");
			}
		}
		
		if(IOPIN0 == 0x00002000)
		{
				Lcd_Command(0XC0);
		}
		
		if(IOPIN0 == 0x00004000)
		{
				Lcd_Command(0XC0);
		}
		
		if(IOPIN0 == 0x00008000)
		{
				Lcd_Command(0XC0);
		}
	}
}