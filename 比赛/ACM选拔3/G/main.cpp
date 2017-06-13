#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define  N 10005

using namespace std;

struct SegTree
{
    int lchild,rchild,key;
};
struct Node
{
    int x,h;
};
SegTree st[4*N];
Node a[10005];
int ans=1;
void Build(int l,int r,int k)
{
    st[k].lchild=l;
    st[k].rchild=r;
    if(l==r)
    {
        st[k].key=a[ans++].h;
        return;
    }
    int m=(l+r)>>1;
    Build(l,m,k<<1);
    Build(m+1,r,k<<1|1);
    st[k].key=max(st[k<<1].key,st[k<<1|1].key);
}
void update(int p,int a,int l,int r,int k)
{
    if(l<=p&&p<=r)
        st[k].key=max(st[k].key,a);
    else
        return;
    if(l==r) return;
    int m=(l+r)>>1;
    if(p<=m)
        update(p,a,st[k<<1].lchild,st[k<<1].rchild,k<<1);
    else
        update(p,a,st[k<<1|1].lchild,st[k<<1|1].rchild,k<<1|1);
}
int Query(int a,int k)
{
    if(st[k].key ==0) return 0;
    if(st[k].key<=a)
    {
        return (st[k].rchild-st[k].lchild+1);
    }
    else
    {
         return Query(a,k<<1)+Query(a,k<<1|1);
    }
}
int main()
{
    int T;scanf("%d",&T);int c=0;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&a[i].x,&a[i].h);
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i].h==0)
            {
                if(i==1)
                    a[i].h=a[i+1].h;
                else if((a[i].x-a[i-1].x)>(a[i+1].x-a[i].x))
                    a[i].h=a[i+1].h;
                else if(a[i].x-(a[i-1].x)<(a[i+1].x-a[i].x))
                    a[i].h=a[i-1].h;
                else
                    a[i].h=min(a[i-1].h,a[i+1].h);
            }
        }
        Build(1,n,1);
//        for(int i=1;i<=7;i++)
//            cout<<st[i].lchild<<' '<<st[i].rchild<<' '<<st[i].key<<endl;
        int k,a,b;scanf("%d",&k);getchar();
        printf("Case #%d:\n",++c);
        for(int i=0;i<k;i++)
        {
            char c;scanf(" %c ",&c);
            if(c=='U')
            {
                scanf("%d %d",&b,&a);
                update(b,a,1,n,1);
//                for(int i=1;i<=7;i++)
//                   cout<<st[i].lchild<<' '<<st[i].rchild<<' '<<st[i].key<<endl;
            }
            else
            {
                scanf("%d",&a);
                printf("%d\n",Query(a,1));
            }
        }

    }
    return 0;
}
