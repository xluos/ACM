#include <iostream>
#include <bits/stdc++.h>
#define INF -0x3f3f3f3f
using namespace std;

int main()
{
    int a[105][105];
    int w;cin>>w;
    while(w--)
    {
        int n,m,sum=0,maxx=INF,max_f=INF,flag=0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]<0)
                {
                    flag++;
                    if(max_f<a[i][j])
                        max_f=a[i][j];
                }
                if(j)a[i][j]+=a[i][j-1];
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=i;j<=m;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    sum+=a[k][j]-a[k][i-1];
                    if(sum<0)sum=0;
                    if(sum>maxx)maxx=sum;
                }
                sum=0;
            }
        }
        if(flag==n*m)
            cout<<max_f<<endl;
        else
            cout<<maxx<<endl;
    }
    return 0;
}
