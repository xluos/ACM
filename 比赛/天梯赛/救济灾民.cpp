#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct mi{
	double dj,zj,zl;
};
bool cmp(mi a,mi b)
{
	return a.dj<b.dj;
}
int main()
{
	mi m[1005];
	int w;cin>>w;
	while(w--)
	{
		int n,q;
		double sum=0;
		cin>>q>>n;
		for(int i=0;i<n;i++)
		{
			cin>>m[i].dj>>m[i].zl;
			m[i].zj=m[i].dj*m[i].zl;
		}
		sort(m,m+n,cmp);
		for(int i=0;i<n;i++)
		{
			if(m[i].zj<q)
			{
				sum += m[i].zl;
				q-=m[i].zj;
			}
			else
			{
				sum += q/m[i].dj;
				break;
			}
		}
		printf("%.2lf\n",sum);
	}
    return 0;
}


