#include <iostream>
#include <stdio.h>
#include <algorithm>
#define N 10005
using namespace std;
struct ren{
	int id,sum,num;
};
bool cmp(ren a,ren b)
{
	if(a.sum==b.sum)
	{
		if(a.num==b.num)
			return a.id<b.id;
		return a.num>b.num;
	}
	return a.sum>b.sum;
}
int main()
{
	ren r[N];
	for(int i=0;i<N;i++)
	{
		r[i].id=i;
		r[i].sum=0;
		r[i].num=0;
	}
	int w;cin>>w;
	for(int i=1;i<=w;i++)
	{
		int n,sum=0;cin>>n;
		while(n--)
		{
			int j,ans;
			cin>>j>>ans;
			r[j].sum += ans;
			r[j].num++;
			sum+=ans;
		}
		r[i].sum -= sum;
	}
	sort(r,r+w+1,cmp);
	for(int i=0;i<=w;i++)
	{
		if(r[i].id)
		printf("%d %.2lf\n",r[i].id,r[i].sum/100.0);
	}
    return 0;
}


