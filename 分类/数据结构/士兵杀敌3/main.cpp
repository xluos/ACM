//#include <iostream>
//#include <algorithm>
//#include <stdio.h>
//#define N 1000005
//using namespace std;
//struct node{
//    int l,r,maxx,minn;
//};
//node sb[4*N];
//void build(int l,int r,int k)
//{
//    sb[k].l=l;sb[k].r=r;
//    if(l==r)
//    {
//        scanf("%d",&sb[k].maxx);
//        sb[k].minn=sb[k].maxx;
//        return;
//    }
//    int mid=(r+l)>>1;
//    build(l,mid,k<<1);
//    build(mid+1,r,k<<1|1);
//    sb[k].maxx=max(sb[k<<1].maxx,sb[k<<1|1].maxx);
//    sb[k].minn=min(sb[k<<1].minn,sb[k<<1|1].minn);
//}
//node query(int l,int r,int k)
//{
//    if(l<=sb[k].l&&r>=sb[k].r)
//    {
//        return sb[k];
//    }
//
//    if(r<=sb[k<<1].r)
//        return query(l,r,k<<1);
//    else if(l>=sb[k<<1|1].l)
//        return query(l,r,k<<1|1);
//    else{
//        int mid = (sb[k].l+sb[k].r)>>1;
//        node a,b,c;
//        a = query(l,mid,k<<1);
//        b = query(mid+1,r,k<<1|1);
//        c.maxx = max(a.maxx,b.maxx);
//        c.minn = min(a.minn,b.minn);
//        return c;
//    }
//}
//int main()
//{
//    int n,m,x,y;
//    scanf("%d %d",&n,&m);
//    build(1,n,1);
//    while(m--)
//    {
//        scanf("%d %d",&x,&y);
//        node aaa;
//        aaa=query(x,y,1);
//        printf("%d\n",aaa.maxx-aaa.minn);
//    }
//    return 0;
//}
///*
//#include <iostream>
//#include <stdio.h>
//#define N 1000005
//using namespace std;
//struct node{
//    int l,r,max,min;
//}ans,_0;
//node sb[4*N];
//node a,b,c;
//maxin build(int l,int r,int k)
//{
//    sb[k].l=l;sb[k].r=r;
//    if(l==r)
//    {
//        scanf("%d",&sb[k].max);
//        sb[k].min=sb[k].max;
//        c.maxx=sb[k].max;
//        c.minn=sb[k].min;
//        return c;
//    }
//    int mid=(r+l)/2;
//    a=build(l,mid,k<<1);
//    b=build(mid+1,r,k<<1|1);
//    sb[k].max=max(a.maxx,b.maxx);
//    sb[k].min=min(a.minn,b.minn);
//}
//maxin query(int l,int r,int k)
//{
//    if(l>r) return _0;
//    if(l==sb[k].l&&r==sb[k].r)
//    {
//        ans.maxx=sb[k].max;
//        ans.minn=sb[k].min;
//        return ans;
//    }
//    if(l>=sb[k].l&&r<=sb[k].r)
//    {
//        maxin a,b;
//        int mid=(sb[k].l+sb[k].r)/2;
//        if(mid>r)mid=r;
//        if(mid<l)mid=l-1;
//        a=query(l,mid,k<<1);
//        b=query(mid+1,r,k<<1|1);
//        ans.maxx=max(a.maxx,b.maxx);
//        ans.minn=min(a.minn,b.minn);
//        return ans;
//    }
//}
//int main()
//{
//    int n,m,l,r;
//    _0.maxx=-1;
//    _0.minn=0x3f3f3f3f;
//    cin>>n>>m;
//    build(1,n,1);
//    while(m--)
//    {
//        scanf("%d %d",&l,&r);
//        ans=query(l,r,1);
//        printf("%d\n",ans.maxx-ans.minn);
//    }
//    return 0;
//}
//*/



#include<stdio.h>

int main()
{
    int N,Q; scanf("%d%d",&N,&Q);

    int v[100001]={0},a[100001]={0},b[100001]={0},t;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&v[i]);
        for(t=i-1;t!=0;)
            if(v[t]<=v[i])
                t=a[t];
            else
                break;
        a[i]=t;
        for(t=i-1;t!=0;)
            if(v[t]>=v[i])
                t=b[t];
            else
                break;
        b[i]=t;
    }
    while(Q--)
    {
        int m,n,t1,max,min; scanf("%d%d",&m,&n);
        for(t1=n,t=a[n]; t>=m; t1=t,t=a[t]);
        max=v[t1];
        for(t1=n,t=b[n]; t>=m; t1=t,t=b[t]);
        min=v[t1];
        printf("%d\n", max-min);
    }
}
