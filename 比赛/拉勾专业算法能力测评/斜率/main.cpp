#include <bits/stdc++.h>
#define WC 0.00000000000001
using namespace std;

struct node{
    int x,y;
    double k;
};
bool cmp(node a,node b)
{
    if(abs(a.k-b.k)>WC)
        return a.k>b.k;
    return
}
int main()
{
    node a[10005];
    int n;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].k=a[i].y*1.0/a[i].x;
    }
    sort(a,a+n,cmp);
    return 0;
}
