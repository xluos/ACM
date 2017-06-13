#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int s,d;
	while(~scanf("%d %d",&s,&d))
	{
		int i=1,sum=0;
		for(;i<=5;i++)
			if((s*(5-i)-i*d)<0)
				break;
		if(i==4)
		sum=s*3-d*9;
		else
		sum=(12-i*2)*s-d*i*2;
		if(sum<=0)
			printf("Deficit\n");
		else
			printf("%d\n",sum);
	}
	return 0;
}
