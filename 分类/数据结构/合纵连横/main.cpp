#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100005
using namespace std;
int pre[3*N],t[3*N];
int n,m,num=1;
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

    while(cin>>n>>m)
    {
        getchar();
        int sum=n;
        for(int i=0;i<n;i++)
            pre[i]=sum++;
        for(int i=n;i<2*n+m+1;i++)
            pre[i]=i;
        for(int i=0;i<m;i++)
        {
            int x,y;
            char c;
//            scanf("%c %d %d",&c,&x,&y);
            scanf(" %c ",&c);
            if(c=='U')
            {
                scanf("%d %d",&x,&y);
                mix(x,y);
            }
            else
            {
                scanf("%d",&x);
                pre[x]=sum++;
            }
        }
        int ans=0;
        memset(t,0,sizeof(t));
        for(int i=0;i<n;i++)
        {
            if(t[Find(i)]++==0)
            {
                ans++;
            }
        }
        printf("Case #%d: %d\n",num++,ans);
    }
    return 0;
}
