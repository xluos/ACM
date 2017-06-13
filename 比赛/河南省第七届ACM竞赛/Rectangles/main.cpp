#include <bits/stdc++.h>
#define N 10005
using namespace std;
struct node{
    double x,y;
}no[N];
bool sort_cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int Search(node b[],node num,int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(num.y>=b[mid].y) low=mid+1;
        else    high=mid-1;
    }
    return low;
}
int lis(node a[],int n)
{
    int k=1;
    node vis[N];
    vis[0]=a[0];
    for(int i=1; i<n; i++)
    {
        if(a[i].y>=vis[k-1].y&&a[i].x>=vis[k-1].x&&(a[i].y!=vis[k-1].y||a[i].x!=vis[k-1].x))
                vis[k++]=a[i];
        else
        {
            int mid=Search(vis,a[i],0,k);
            vis[mid]=a[i];
        }
    }
    return k;
}
int dig(int x)
{
    return (x + 8) % 9 + 1;
}
int main()
{
    while(1){
    int T;cin>>T;

    cout<<dig(T)<<endl;

    }
//    while(T--)
//    {
//        double k1,k2;
//        int l[N];
//        int a,b,c,d,n,p=0;
//        scanf("%d",&n);
//        for(int i=0;i<n;i++)
//        {
//            scanf("%d%d",&a,&b);
//            no[p].x=max(a,b);
//            no[p].y=min(a,b);
//            l[p]=1;
//            p++;
//        }
//        sort(no,no+p,sort_cmp);
//        cout<<lis(no,p)<<endl;
//    }
    return 0;
}
