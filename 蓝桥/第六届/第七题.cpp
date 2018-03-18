#include<stdio.h>
//答案  2872 X错误   正确答案  3598180 
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
