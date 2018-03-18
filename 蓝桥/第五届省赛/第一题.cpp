#include<stdio.h>
//11 30
int main()
{
	for(int i=0;i<40;i++)
	{
		for(int j=0;j<40;j++)
		{
			if(23*i+19*j == 823)
			{
				printf("%d %d",i,j);
			}
		}
	}
	return 0;
}
