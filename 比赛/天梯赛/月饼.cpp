#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct yvebing{
	double kc,jg,xjb;
};
bool cmp(yvebing a,yvebing b)
{
	return a.xjb>b.xjb;
}
int main()
{
	yvebing yb[1005];
	int n;
	double kucun,sum;
	cin>>n>>kucun;
	for(int i=0;i<n;i++)
	{
		cin>>yb[i].kc;
	}
	for(int i=0;i<n;i++)
	{
		cin>>yb[i].jg;
		yb[i].xjb=yb[i].jg/yb[i].kc;
	}
	sort(yb,yb+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(yb[i].kc<kucun)
		{
			kucun -= yb[i].kc;
			sum += yb[i].jg;
		}
		else
		{
			sum += yb[i].xjb*kucun;
			break;
		}
	}
	printf("%.2lf\n",sum);
    return 0;
}


