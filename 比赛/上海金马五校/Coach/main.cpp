#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define N 5010
using namespace std;
int pre[N],t[N];
int n,m;
int Find(int x)
{
    int r=x;
    while(r!=pre[r])
        r=pre[r];
    int i=x,j;
    while(pre[i]!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void mix(int i,int j)
{
    int fx=Find(i),fy=Find(j);
    if(fx!=fy)
    {
        pre[fy]=fx;
    }
}
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        int flag=0;
        for(int i=0;i<=n;i++)
            pre[i]=i;
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            mix(x,y);
        }
        map<int,int>mp;
        for(int i=1;i<=n;i++)
        {
            mp[Find(i)]++;
        }
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
        {
            if((it->second)%3)
            {
                printf("No\n");
                flag=1;
                break;
            }
        }
        if(flag)continue;
        printf("Yes\n");
    }
}
