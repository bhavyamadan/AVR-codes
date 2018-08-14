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

void number(unsigned char a)
{

	int b,c;
	LCDcmd(0x04);	
	b=a%10;
	LCDdata(b+48);
	a=a/10;
	c=a%10;
	LCDcmd(0x06);	
	LCDdata(c+48);

}

void main()
{

	DDRB=0xff;
	DDRB=0xff;
	DDRC=0x00;

	LCDcmd(0x38);
    LCDcmd(0x0E);
	
	int s,i,j,k;

	while(1)
	{
		PINC=0xff;
		s=PINC & 0x1111111;
		LCDcmd(0x80);
		String("    COUNTER");
		if(s!=0x1011111)
		{
			for(i=0;i<60;i++)
			{
				LCDcmd(0xC4);
				number(i);
				LCDcmd(0xC5);
				LCDdata(':');
				for(j=0;j<60;j++)
				{
					LCDcmd(0xC7);
					number(j);
					LCDcmd(0xC8);
					LCDdata(':');
					for(k=0;k<60;k++)
					{
						LCDcmd(0xCA);
						number(k);
						
					}
				}
			}
		}
		else
		{
			LCDcmd(0xC4);
			number('00');
			LCDcmd(0xC5);
			LCDdata(':');
			LCDcmd(0xC7);
			number('00');
			LCDcmd(0xC8);
			LCDdata(':');
			LCDcmd(0xCA);
			number('00');
		}
	}

}
