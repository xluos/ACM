#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int main()
{
	set<int>se[51];
	int w,m,n,ans;
	cin>>w;
	for(int i=0;i<w;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&ans);
			se[i].insert(ans);
		}
	}
	set<int>::iterator it;
	cin>>w;
	while(w--)
	{
		int ans=0;
		cin>>n>>m;
		for(it=se[m-1].begin();it!=se[m-1].end();it++)
		{
			if(se[n-1].find(*it)!=se[n-1].end())
				ans++;
		}
		printf("%.2lf%%\n",ans/(se[n-1].size()+se[m-1].size()-ans*1.0)*100);
	}
	return 0;
}
/*int main()               //Map版本，最后数据超时；
{
	int w,m,n,x[50][10001];
	cin>>w;
	for(int i=0;i<w;i++)
	{
		cin>>n;
		x[i][0]=n;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&x[i][j]);
		}
	}
	map<int,int>mp;
	cin>>w;
	while(w--)
	{
		int ans=0;
		cin>>n>>m;
		mp.clear();
		for(int i=1;i<=x[n-1][0];i++)
		{
			if(mp[x[n-1][i]]==0)
				mp[x[n-1][i]]++;
		}
		for(int i=1;i<=x[m-1][0];i++)
		{
			if(mp[x[m-1][i]]==0)
				mp[x[m-1][i]]=-1;
			else if(mp[x[m-1][i]]==1)
			{
				mp[x[m-1][i]]++;
				ans++;

			}
		}
		//cout<<ans<<endl;
		//cout<<mp.size()<<endl;
		printf("%.2lf%%\n",ans/(1.0*mp.size())*100);
	}
	return 0;
	
}

*/

/*#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int a,b,c,d,i,sum,e,f,g;
    int s[1000],h[1000];
    scanf("%d",&a);
    for(e=2;e<=a;e++)
    {
        i=0;
        sum=0;
        for(b=1;b<e;b++)
        {
            if(e%b==0)
            {
                s[i]=b;
                i++;
            }
        }
        for(c=0;c<i;c++)
        {
            sum=sum+s[c];
        }
        if(sum==e)
        {
            printf("%d its factors are",e);
            for(d=0;d<i;d++)
            {
                printf(" %d",s[d]);
            }
            printf("\n");
        }
    }
   return 0;
}*/

