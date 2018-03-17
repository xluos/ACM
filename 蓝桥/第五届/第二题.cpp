#include<stdio.h>

int main()
{
	double i=1,sum=0;
	while(sum<15)
	{
		sum += 1/i;
		i++;
	}
	printf("%lf %lf",sum,i-1);
	return 0;
} 
