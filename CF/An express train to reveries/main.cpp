#include <bits/stdc++.h>

using namespace std;
int a[1005],b[1005],c[1005],d[1005];
int aa[1005],bb[1005],vis[1005]={0};
int n,flag=0;
int pan(int a[],int b[],int n)
{
    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
        return 0;
    return 1;
}
void bfs(int t,int k)
{
    if(t==k)
    {
        flag=1;
        return ;
    }
    for(int i=0;i<k;i++)
    {
        if(!vis[i])
        {
            if((c[i]==aa[t]&&c[i]!=bb[t])||(c[i]!=aa[t]&&c[i]==bb[t])||(k==1&&c[i]!=aa[t]&&c[i]!=bb[t]))
            {
                vis[i]=1;
                d[t]=c[i];
                bfs(t+1,k);
                vis[i]=0;
            }
        }
        if(flag)return ;
    }
}
int myrandom (int i) { return std::rand()%i;}
int main()
{
    int ak=0,bk=0,k=0;
    cin>>n;
    map<int,int>mp;
    int ans[1005];
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        if(b[i]!=a[i])
        {
            aa[ak]=a[i];ak++;
            bb[bk]=b[i];bk++;
            a[i]=0;
            b[i]=0;
        }
        else
        {
            ans[a[i]]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==-1)
        {
            c[k]=i;
            k++;
        }
    }
    bfs(0,k);
    for(int i=0,j=0;i<n;i++)
    {
        if(!a[i])
        {
            printf("%d%c",d[j],i==(n-1)?'\n':' ');
            j++;
        }
        else
            printf("%d%c",a[i],i==(n-1)?'\n':' ');
    }
    return 0;
}
