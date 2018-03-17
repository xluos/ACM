#include<stdio.h>
#include<math.h>
#include<windows.h>
#define Time_init	LARGE_INTEGER lFrequency; \
					QueryPerformanceFrequency(&lFrequency);
#define Time_begin	LARGE_INTEGER lBeginCount; \
					QueryPerformanceCounter(&lBeginCount);
#define Time_end	LARGE_INTEGER lEndCount; \
					QueryPerformanceCounter(&lEndCount);
#define Time_out	double time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart; \
					printf("运行时间%lf毫秒",time*1000);					
int D(double a,double b)
{
	return fabs(a-b)<0.0000001?1:0;
}
int main()
{
	Time_init;
	double n;
	int sum=0;
	scanf("%lf",&n);
	Time_begin;
	double N = n*n;
	for(double i=1;i<n/sqrt(2);i++)
	{
		double fans = N - i*i;
		double ans = sqrt(fans);
		//if(D(fans,ans*ans))
		if(ans == (int)ans) 
		{
			//printf("i=%lf  ans=%lf\n",i,ans);
			sum++;
		}
	}
	printf("%d\n",sum);
	Time_end;
	Time_out;
	return 0;
}
