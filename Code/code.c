	 #include<reg51.h>
	sbit R0 = P0^6;
	sbit Y0 = P0^0;
	sbit G0 = P1^4;
	sbit R1 = P0^4;
	sbit Y1 = P1^7;
	sbit G1 = P1^2;
 	sbit R2 = P0^2;
	sbit Y2 = P1^6;
	sbit G2 = P1^0;
void delay_ms(unsigned int del)
{
unsigned int i,j;
for(i = 0; i < del; i ++)
for(j = 0; j < 1275; j ++);
}
#define RESET_DELAY 1000         // (aprox 1 second)
#define RED_DELAY 3000           // (aprox 1 second)
#define YELLOW_DELAY 1000        // (aprox 1 second)
#define GREEN_DELAY 3000        // (aprox 3 second)

void main()
{
// Initialize all lights////////
// Switch on all red signals.
R0 = R1 = R2 = 0;
// Switch off all other signals.
Y0 = Y1 = Y2 = G0 = G1 = G2 = 1;
delay_ms(RESET_DELAY);
////////////////////////////////
while(1)

 {
// First service way 0.////////////////////
// Switch on yellow of way 0.
		Y0 = 0;
		delay_ms(YELLOW_DELAY);
// Switch off red and yellow of way 0 and
// switch on green of way 0.
		R2 = 0;
		R0 = 1;
		Y0 = 1;
		G0 = 0;
		delay_ms(GREEN_DELAY);
// Switch off green of way 0 and
// switch on yellow of way 0;
	G0 = 1;
	Y0 = 0;
	Y1 = 0;
	delay_ms(YELLOW_DELAY);
// Switch off yellow of way 0 and
// switch on red of way 0;
	Y0 = 1;
	Y1 = 1;
	R0 = 0;
	G1 = 0;
	delay_ms(GREEN_DELAY);
/////////////////////////////////////////
// Now service way 1.////////////////////
// Switch on yellow of way 1.
	Y1 = 0;
	delay_ms(YELLOW_DELAY);
// Switch off red and yellow of way 1 and
// switch on green of way 1.
	R1 = 1;
	Y1 = 1;
	G1 = 0;
	delay_ms(GREEN_DELAY);
// Switch off green of way 1 and
// switch on yellow of way 1;
	G1 = 1;
	Y1 = 0;
	Y2 = 0;
	delay_ms(YELLOW_DELAY);
// Switch off yellow of way 1 and
// switch on red of way 1;
	Y1 = 1;
	Y2 = 1;
	R1 = 0;
	G2 = 0;
	delay_ms(GREEN_DELAY);
	Y2 = 0;
	G2 = 1;
	
}
   }
