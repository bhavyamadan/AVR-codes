#include<avr/io.h>
#include<util/delay.h>

#define RS PB0
#define RW PB1
#define EN PB2

void LCDcmd(unsigned char a)
{
	PORTD=a;
	PORTB&=~(1<<RS);
	PORTB&=~(1<<RW);
	PORTB|=(1<<EN);
	_delay_ms(10);
	PORTB&=~(1<<EN);
}
void LCDdata(unsigned char a)
{
	PORTD=a;
    PORTB|=(1<<RS);
    PORTB&=~(1<<RW);
    PORTB|=(1<<EN);
    _delay_ms(10);
    PORTB&=~(1<<EN);
}
void String(char * str)
{
	int i=0;
    LCDcmd(0x38);
    LCDcmd(0x0E);
	while(str[i]!='\0')
	{
		LCDdata(str[i]);
		i++;
	}
}

/*void Integer(int num)
{
	LCDcmd(0x38);
    LCDcmd(0x0E);
	LCDdata(num+48);
	//LCDdata(num+48);

}*/
void main()
{
	DDRD=0xff;
    DDRB=0xff;
	
	/*int top[]={' ','D','I','G','I','T','A','L',' ','C','L','O','C','K',' '};
    while(i<16)
    {
       LCDcmd(0x38);
       LCDcmd(0x0E);
       LCDdata(top[i]);
	   i++;
    }*/
	String(" Digital Clock");
	while(1)
	{
		int h1=0,h2=0,m1=0,m2=0,s1=0,s2=0;

		for(h1=0;h1<6;h1++)
		{
			LCDcmd(0xC3);
			LCDdata(h1+48);
			for(h2=0;h2<10;h2++)
			{
				LCDcmd(0xC4);
				LCDdata(h2+48);
				LCDdata(':');
				for(m1=0;m1<6;m1++)
				{
					LCDcmd(0xC6);
					LCDdata(m1+48);
					for(m2=0;m2<10;m2++)
					{
						LCDcmd(0xC7);
						LCDdata(m2+48);
						LCDdata(':');
						for(s1=0;s1<6;s1++)
						{
							LCDcmd(0xC9);
							LCDdata(s1+48);
							for(s2=0;s2<10;s2++)
							{
								LCDcmd(0xCA);
								LCDdata(s2+48);
								_delay_ms(10);
								
							}
						}
					}
				}
			}
		}
	}
}
