#include<stdio.h>
//��  2872 X����   ��ȷ��  3598180 
int count = 0;
void getScheme(int n,int m)
{
	if(n>13) return ;
	if(m==13)
	{
		if(n == 13) count++;
		return ;
	}
	for(int i=0;i<=4;i++)
	{
		getScheme(n+i,m+1);
	}
}
int main()
{
	getScheme(0,0);
	printf("%d\n",count);
	return 0;
} 
