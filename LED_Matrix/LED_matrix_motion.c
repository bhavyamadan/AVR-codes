#include<avr/io.h>
#include<util/delay.h>

void main()
{

DDRA=0b11111111;
DDRB=0b11111111;

int B[3]={0b00000010,0b01000000,0b00111100};
int H[2]={0b00100010,0b00111110};
int A[2]={0b00100010,0b00111110};
int V[4]={0b00100010,0b00010100,0b00001000,0b00001000};
int Y[3]={0b00100010,0b00010100,0b00001000};
int A1[2]={0b00100010,0b00111110};
int i,j;

while(1)
{
// Letter B
for(j=0;j<8;j++)	
{	
	for(i=0;i<300;i++)
	{
		PORTA=B[0];
		PORTB=0b10000001;
		_delay_ms(1);
		PORTA=0;

		PORTA=B[1];
		PORTB=0b11010011;
		_delay_ms(1);
		PORTA=0;

		PORTA=B[2];
		PORTB=0b10101101;
		_delay_ms(1);
	}

	B[0]=B[0]/2;
	B[1]=B[1]/2;
	B[2]=B[2]/2;
}

PORTA=0;
PORTB=0;

// Letter H
for(j=0;j<8;j++)	
{
	for(i=0;i<300;i++)
	{
		PORTA=H[0];
		PORTB=0b10000001;
		_delay_ms(1);
		PORTA=0;

		PORTA=H[1];
		PORTB=0b11101111;
		_delay_ms(1);
	}
	H[0]=H[0]/2;
	H[1]=H[1]/2;
}

PORTA=0;
PORTB=0;

// Letter A
for(j=0;j<8;j++)	
{
	for(i=0;i<300;i++)
	{
		PORTA=A[0];
		PORTB=0b11000011;
		_delay_ms(1);
		PORTA=0;

		PORTA=A[1];
		PORTB=0b11101101;
		_delay_ms(1);
	}
	A[0]=A[0]/2;
	A[1]=A[1]/2;

}

PORTA=0;
PORTB=0;

// Letter V
for(j=0;j<8;j++)	
{
	for(i=0;i<300;i++)
	{
		PORTA=V[0];
		PORTB=0b11100001;
		_delay_ms(1);
		PORTA=0;

		PORTA=V[1];
		PORTB=0b11011111;
		_delay_ms(1);
		PORTA=0;
	
		PORTA=V[2];
		PORTB=0b10111111;
		_delay_ms(1);
		PORTA=0;

		PORTA=V[3];
		PORTB=0b11111111;
		_delay_ms(1);
		PORTA=0;

	}
	V[0]=V[0]/2;
	V[1]=V[1]/2;
	V[2]=V[2]/2;
	V[3]=V[3]/2;
}
PORTA=0;
PORTB=0;

// Letter Y
for(j=0;j<8;j++)	
{
	for(i=0;i<300;i++)
	{
		PORTA=Y[0];
		PORTB=0b11111101;
		_delay_ms(1);
		PORTA=0;

		PORTA=Y[1];
		PORTB=0b11111011;
		_delay_ms(1);
		PORTA=0;
	
		PORTA=Y[2];
		PORTB=0b10000111;
		_delay_ms(1);
		PORTA=0;
	}

	Y[0]=Y[0]/2;
	Y[1]=Y[1]/2;
	Y[2]=Y[2]/2;
}

PORTA=0;
PORTB=0;

// Letter A
for(j=0;j<8;j++)	
{
	for(i=0;i<300;i++)
	{
		PORTA=A1[0];
		PORTB=0b11000011;
		_delay_ms(1);
		PORTA=0;

		PORTA=A1[1];
		PORTB=0b11101101;
		_delay_ms(1);
	}
	A1[0]=A1[0]/2;
	A1[1]=A1[1]/2;

}

PORTA=0;
PORTB=0;

}

}
