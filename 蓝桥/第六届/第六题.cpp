#include<stdio.h>
//  ´ğ°¸16 24 
int judeg(int n,int m)
{
	int sum=0;
	for(int i=1;i<50;i++)
	{
		if(i==n+1||i==m+1)
		{
			sum -= i-1;
			sum += (i-1)*i;
		}
		else
		{
			sum += i;
		}
	}
	//printf("i==%d j==%d sum==%d\n",n,m,sum);
	if(sum == 2015) return 1;
	return 0;
}
int main()
{
	for(int i=1;i<49;i++)
	{
		for(int j =i+1;j<49;j++)
		{
			if(judeg(i,j)) printf("%d %d\n",i,j);
		}
	}
	return 0;
}
