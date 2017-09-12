#include "reg51.h" 
sbit led=P1^0;
sbit led1=P1^1;
void day(int n)
{
	int i,j;
	//for(i=0;i<n;i++)
	for(j=0;j<n;j++);	
}
void main()
{
	
	while(1)
	{
		led=0;
		led1=0;
		day(200);
		led1=1;
		day(200);
	}
}