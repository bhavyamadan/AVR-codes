#include<avr/io.h>
#include<util/delay.h>

#define RS PB0
#define RW PB1
#define EN PB2

void LCDCMD(unsigned char a)
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
void main()
{
	int up[]={' ',' ',' ',' ','U','V',' ','S','O','F','T',' ',' ',' ',' ',' '};
	int i=0;
	DDRD=0xff;
    DDRB=0xff;
    while(i<16)
	{
		LCDCMD(0x38);
    	LCDCMD(0x0E);
    	LCDdata(up[i]);
		i++;
	}
	while(1)
    {
    	for(i=0xCF;i>0xB0;i--)
		{
			LCDCMD(i);
			LCDdata('1');
			LCDdata(' ');
			LCDdata('R');
			LCDdata('o');
			LCDdata('b');
			LCDdata('o');
			LCDdata('t');
			LCDdata('i');
			LCDdata('c');
			LCDdata('s');
			LCDdata(' ');	
		}   
		for(i=0xCF;i>0xB0;i--)
		{
			LCDCMD(i);
			LCDdata('2');
			LCDdata(' ');
			LCDdata('M');
			LCDdata('a');
			LCDdata('t');
			LCDdata('l');
			LCDdata('a');
			LCDdata('b');
			LCDdata(' ');	
		}   
    }
}

