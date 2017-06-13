#include <bits/stdc++.h>
#define N 33
using namespace std;
struct node{
    int l,r,h;
}f[3*N];
int h[3*N];
bool cmp(node a,node b)
{
    if(a.l==b.l)
    {
        if(a.r==b.r)
        {
            return a.h>b.h;
        }
        else
        {
            return a.r<b.r;
        }
    }
    return a.l<b.l;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int a,b,c,t=0,ma=0,max_h=0,flag=0;
        memset(h,0,sizeof(h));
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(a>c)swap(a,c);
            if(a>b)swap(a,b);
            if(b>c)swap(b,c);
            max_h=max(max_h,c);
            f[t].r=a;f[t].l=b;f[t++].h=c;
            f[t].r=b;f[t].l=c;f[t++].h=a;
            f[t].r=a;f[t].l=c;f[t++].h=b;
        }
        sort(f,f+t,cmp);
        for(int i=1;i<t;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(f[j].r<=f[i].r&&f[j].l<=f[i].l&&f[j].h+h[j]>h[i])
                {
                    if(f[j].r==f[i].r&&f[j].l==f[i].l)
                        continue;
                    flag=1;
                    h[i]=f[j].h+h[j];
                    if(ma<h[i])ma=h[i];
                }
            }
        }
        if(flag)
            printf("%d\n",ma);
        else
            printf("%d\n",max_h);
    }
    return 0;
}
