#include<stdio.h>
#include<math.h>
//´ð°¸2.506184
int main ()
{
	double low=2,md,height = 3;
	while(1)
	{
		md = (low + height)/2.0;
		double x = pow(md,md);
		if(fabs(x-10)<0.0000000000001)
		{
			
			printf("x == %lf   md == %.16lf",x,md);
			return 0;
		}
		if(x-10 > 0)
		{
			height = md;
		}
		else
		{
			low = md;
		}
	} 
	return 0;
}
