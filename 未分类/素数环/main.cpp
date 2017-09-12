#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[22],vis[22],ss[44];
int n;
void chushi()
{
    memset(vis,0,sizeof(vis));
    ss[0]=ss[1]=0;
    ss[2]=1;
    for(int i=3;i<42;i++)
    {
        int k=1;
        for(int j=2;j<i;j++)
            if(i%j==0)
            {
                k=0;ss[i]=0;
                break;
            }
        if(k)
            ss[i]=1;
    }
}
void suhuan(int cs)
{
    if(cs==n&&ss[a[0]+a[n-1]])
    {
        for(int i=0;i<n;i++)
        {
            if(i==0)
                printf("%d",a[i]);
            else
                printf(" %d",a[i]);
        }
        printf("\n");
    }
    else
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]&&ss[a[cs-1]+i])
        {
            vis[i]=1;
            a[cs]=i;
            suhuan(cs+1);
            vis[i]=0;
        }
    }
}
int main()
{
    chushi();int i=0;
    while(~scanf("%d",&n))
    {
        a[0]=1;
        printf("Case %d:\n",i+1);
        suhuan(1);
        printf("\n");
        i++;
    }
    return 0;
}
