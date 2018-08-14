#include<avr/io.h>
#include<util/delay.h>

#define RS PB0
#define RW PB1
#define EN PB2

void LCDcmd(unsigned char a)
{
	PORTA=a;
	PORTB&=~(1<<RS);
	PORTB&=~(1<<RW);
	PORTB|=(1<<EN);
	_delay_ms(10);
	PORTB&=~(1<<EN);
}

void LCDdata(unsigned char a)
{
	PORTA=a;
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

void main()
{
	int s,flag[]={1,1,1,1,1,1,1,1,1};int p=0;
	DDRA=0xff;
	DDRB=0xff;
	DDRC=0x00;
	DDRD=0xff;
	LCDcmd(0x38);
    LCDcmd(0x0E);
	String("     Welcome ");
	_delay_ms(1000);
	LCDcmd(0x80);
	String("   You Pressed ");
	PORTD=0b11111110;
	while(1)
	{	
		PINC=0xff;
		
		switch(PORTD)
		{
			case 0b11111110:
				PORTD=0b11111101;
			break;
			case 0b11111101:
				PORTD=0b11111011;
			break;
			case 0b11111011:
				PORTD=0b11110111;
			break;
			case 0b11110111:
				PORTD=0b11111110;
			break;
		}
		s=(PINC & 0b11111111); 
		switch(s)
		{
		case 0b11111110:
			switch(PORTD)
			{
				case 0b11111110:
					LCDcmd(0xC8);
					p++;
					switch(p)
					{
					case 1:
						LCDdata('1');
						
						_delay_ms(200);
					break;
					case 2:
						LCDdata('a');
						flag[0]++;
						_delay_ms(200);
					break;
					case 3:
						LCDdata('b');
						flag[0]++;
						_delay_ms(200);
					break;
					case 4:
						LCDdata('c');
					p=0;
						_delay_ms(200);
					break;
					}	
				break;
				case 0b11111101:
					LCDcmd(0xC8);
					if(flag[3]%4==1)
					{	LCDdata('4');
						
					}
					else if(flag[3]%4==2)
					{	LCDdata('j');
						
					}
					else if(flag[3]%4==3)
					{	LCDdata('k');
						
					}
					else if(flag[3]%4==0)
					{	LCDdata('l');
						
					}
					flag[3]++;
				break;
				case 0b11111011:
					LCDcmd(0xC8);
					if(flag[6]%4==1)
					{	LCDdata('7');
						
					}
					else if(flag[6]%4==2)
					{	LCDdata('s');
						
					}
					else if(flag[6]%4==3)
					{	LCDdata('t');
						
					}
					else if(flag[6]%4==4)
					{	LCDdata('u');
						
					}
					flag[6]++;
				break;
				case 0b11110111:
					LCDcmd(0xC8);
					LCDdata('*');
				break;
			}
			break;	
		case 0b11111101:
			switch(PORTD)
			{
				case 0b11111110:
					LCDcmd(0xC8);
					switch(flag[1])
					case 1:
						LCDdata('2');
						flag[1]++;
					break;
					case 2:
						LCDdata('d');
						flag[1]++;
					break;
					case 3:
						LCDdata('e');
						flag[1]++;
					break;
					case 4:
						LCDdata('f');
						flag[1]=1;
					break;	
				break;
				case 0b11111101:
					LCDcmd(0xC8);
					if(flag[4]==1)
					{	LCDdata('5');
						flag[4]++;
					}
					else if(flag[4]==2)
					{	LCDdata('m');
						flag[4]++;
					}
					else if(flag[4]==3)
					{	LCDdata('n');
						flag[4]++;
					}
					else if(flag[4]==4)
					{	LCDdata('o');
						flag[4]=1;
					}
				break;
				case 0b11111011:
					LCDcmd(0xC8);
					if(flag[7]==1)
					{	LCDdata('8');
						flag[7]++;
					}
					else if(flag[7]==2)
					{	LCDdata('v');
						flag[7]++;
					}
					else if(flag[7]==3)
					{	LCDdata('w');
						flag[7]++;
					}
					else if(flag[7]==4)
					{	LCDdata('x');
						flag[7]=1;
					}
				break;
				case 0b11110111:
					LCDcmd(0xC8);
					LCDdata('0');
				break;
			}	
			break;
		case 0b11111011:
			switch(PORTD)
			{
				case 0b11111110:
					LCDcmd(0xC8);
					switch(flag[2])
					case 1:
						LCDdata('3');
						flag[2]++;
					break;
					case 2:
						LCDdata('g');
						flag[0]++;
					break;
					case 3:
						LCDdata('h');
						flag[0]++;
					break;
					case 4:
						LCDdata('i');
						flag[0]=1;
					break;	
				break;
				case 0b11111101:
					LCDcmd(0xC8);
					if(flag[5]==1)
					{	LCDdata('6');
						flag[5]++;
					}
					else if(flag[5]==2)
					{	LCDdata('p');
						flag[5]++;
					}
					else if(flag[5]==3)
					{	LCDdata('q');
						flag[5]++;
					}
					else if(flag[5]==4)
					{	LCDdata('r');
						flag[5]=1;
					}
				break;
				case 0b11111011:
					LCDcmd(0xC8);
					if(flag[8]==1)
					{	LCDdata('9');
						flag[8]++;
					}
					else if(flag[8]==2)
					{	LCDdata('y');
						flag[8]++;
					}
					else if(flag[8]==3)
					{	LCDdata('z');
						flag[8]=1;
					}
				break;
				case 0b11110111:
					LCDcmd(0xC8);
					LCDdata('#');
				break;
			}
			break;
		}		
	}
}
