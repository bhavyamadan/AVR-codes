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
	_delay_ms(100);
	PORTB&=~(1<<EN);
}
void LCDdata(unsigned char a)
{
	PORTD=a;
    PORTB|=(1<<RS);
    PORTB&=~(1<<RW);
    PORTB|=(1<<EN);
    _delay_ms(100);
    PORTB&=~(1<<EN);
}
void main()
{
	DDRD=0xff;
    DDRB=0xff;
    while(1)
    {
       LCDCMD(0x38);
       LCDCMD(0x0E);
       LCDdata('P');
    }
}

