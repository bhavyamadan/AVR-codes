#include<avr/io.h>
#include<util/delay.h>

void main()
{

DDRA=0b11111111;
DDRB=0b11111111;

int i;

while(1)
{
// Letter B
for(i=0;i<600;i++)
{
	PORTA=0b00000010;
	PORTB=0b10000001;
	_delay_ms(1);
	PORTA=0;

	PORTA=0b01000000;
	PORTB=0b11010011;
	_delay_ms(1);
	PORTA=0;

	PORTA=0b00111100;
	PORTB=0b10101101;
	_delay_ms(1);
}

PORTA=0;
PORTB=0;

// Letter H
for(i=0;i<600;i++)
{
	PORTA=0b00100010;
	PORTB=0b10000001;
	_delay_ms(1);
	PORTA=0;

	PORTA=0b00111110;
	PORTB=0b11101111;
	_delay_ms(1);
}

PORTA=0;
PORTB=0;

// Letter A
for(i=0;i<600;i++)
{
	PORTA=0b00100010;
	PORTB=0b11000011;
	_delay_ms(1);
	PORTA=0;

	PORTA=0b00111110;
	PORTB=0b11101101;
	_delay_ms(1);
}

PORTA=0;
PORTB=0;

// Letter V
for(i=0;i<600;i++)
{
	PORTA=0b00100010;
	PORTB=0b11100001;
	_delay_ms(1);
	PORTA=0;

	PORTA=0b00010100;
	PORTB=0b11011111;
	_delay_ms(1);
	PORTA=0;
	
	PORTA=0b00001000;
	PORTB=0b10111111;
	_delay_ms(1);
	PORTA=0;

	PORTA=0b00001000;
	PORTB=0b11111111;
	_delay_ms(1);
	PORTA=0;

}

PORTA=0;
PORTB=0;

// Letter Y
for(i=0;i<600;i++)
{
	PORTA=0b00100010;
	PORTB=0b11111101;
	_delay_ms(1);
	PORTA=0;

	PORTA=0b00010100;
	PORTB=0b11111011;
	_delay_ms(1);
	PORTA=0;
	
	PORTA=0b00001000;
	PORTB=0b10000111;
	_delay_ms(1);
	PORTA=0;

}

PORTA=0;
PORTB=0;

// Letter A
for(i=0;i<600;i++)
{
	PORTA=0b00100010;
	PORTB=0b11000011;
	_delay_ms(1);
	PORTA=0;

	PORTA=0b00111110;
	PORTB=0b11101101;
	_delay_ms(1);
}

PORTA=0;
PORTB=0;

}

}
