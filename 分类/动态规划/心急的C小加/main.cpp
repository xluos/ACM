#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define N 5005  //最大长度
using namespace std;
struct node{
    int l,w;
};
bool cmp(node a,node b)
{
    if(a.l>=b.l&&a.w>=b.w)
        return false;
    else
        return true;
}
bool sort_cmp(node a,node b)
{
    if(a.l==b.l)
        return a.w>b.w;
    return a.l>b.l;
}
int lis(node a[],int n)//a[]为输入的序列，n为序列长度
{
    int k=1;
    node vis[N];
    vis[0]=a[0];
    for(int i=1; i<n; i++)
    {
        if(a[i].l>vis[k-1].l||a[i].w>vis[k-1].w)  //增减规则
            vis[k++]=a[i];
        else
        {
            int mid=lower_bound(vis,vis+k,a[i],cmp)-vis;
            vis[mid]=a[i];
        }
    }
    return k; //返回lis长度
}
int main()
{
    int w;
    node x[N];
    //LIS  最长递增子序列   O（Nlongn）
    int n;
    cin>>n;
    while(n--)
    {
        scanf("%d",&w);
        for(int i=0; i<w; i++)
        {
            scanf("%d %d",&x[i].l,&x[i].w);
        }
        sort(x,x+w,sort_cmp;
        cout<<lis(x,w)<<endl;
    }
    return 0;
}







/*#include <algorithm>
#include <cstdio>
using namespace std;
struct node{
    int l,w;
}data[5005];
int vis[5005];
bool cmp(node a,node b)
{
    if(a.l==b.l)
        return a.w>b.w;
    return a.l>b.l;
}
int main()
{
    int w;
    scanf("%d",&w);
    while(w--)
    {
        int n,sum=0;
        node ans;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&data[i].l,&data[i].w);
            vis[i]=0;
        }
        sort(data,data+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(vis[i])continue;
            ans=data[i];
            vis[i]=1;
            for(int j=i+1;j<n;j++)
            {
                if(ans.l>=data[j].l&&ans.w>=data[j].w&&!vis[j])
                {
                    ans=data[j];
                    vis[j]=1;
                }
            }
            sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
*/
