#include<lpc214x.h>
#include "LPC2148_delay.h"

int sin_wave[43] = {0,6,25,55,97,151,211,216,282,359,436,512,591,665,742,808,873,926,968,998,1017,1023,1017,998,968,926,873,808,742,665,591,512,436,359,282,216,211,151,97,55,25,6,0};
	
int main()
{
	PINSEL0 = 0x00000000;
	PINSEL1 = 0x00080000;
	IOPIN0  = 0X00000000;

	int k,SW=0;

	while(1)
	{
		if((IOPIN0 == 0X00000001))
		{
			for(k=0; k<=42; k++)
			{
				DACR=(sin_wave[k]<<6);
				delay(10);
			}
		}

		if((IOPIN0 == 0X00000002))
		{
			for(k=0; k<=1024; k++)
			{
				DACR=(k<<6);
				delay(1);
			}
		}
		
		if((IOPIN0 == 0X00000004))
		{
			while(k != 1023)
			{
				DACR = ( (1<<16) | (k<<6) );
				k++;
				delay(1);
			}
			while(k != 0)
			{
				DACR = ( (1<<16) | (k<<6) );
				k--;
				delay(1);
			}
		}
		
		if((IOPIN0 == 0X00000008))
		{
			k = 1023;
			DACR = ( (1<<16) | (k<<6) );
			delay(100);
			k = 0;
			DACR = ( (1<<16) | (k<<6) );
			delay(100);
			
		}
	}
}