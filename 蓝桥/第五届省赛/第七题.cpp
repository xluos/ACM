#include<stdio.h>
#include<algorithm>
#include<windows.h>
#define Time_init	LARGE_INTEGER lFrequency; \
QueryPerformanceFrequency(&lFrequency);
#define Time_begin	LARGE_INTEGER lBeginCount; \
QueryPerformanceCounter(&lBeginCount);
#define Time_end	LARGE_INTEGER lEndCount; \
QueryPerformanceCounter(&lEndCount);
#define Time_out	double time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart; \
printf("运行时间%lf毫秒",time*1000);
using namespace std;
int judeg(int a[])
{
	for(int i=1;i<6;i++)
	{
		if(a[i]!=a[i-1])
			return 0;
	}
	return 1;
}
int main()
{
	Time_init
	Time_begin
	int a[] = {2,4,5,6,7,9,10,11,12};
	int b[6];
	do
	{
		b[0]=8+a[0]+a[1]+a[2];
		b[1]=1+a[0]+a[3]+a[5];
		b[2]=1+a[1]+a[4]+a[8];
		b[3]=8+a[3]+a[6]+3;
		b[4]=a[2]+a[4]+a[7]+3;
		b[5]=a[5]+a[6]+a[7]+a[8]; 
		if(judeg(b))
		{
			printf("%d\n",a[3]);
			break;
		}
	}while(next_permutation(a,a+9));
	Time_end
	Time_out
}
