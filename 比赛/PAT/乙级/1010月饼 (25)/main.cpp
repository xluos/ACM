#include <bits/stdc++.h>

using namespace std;
struct node
{
    double jia,liang,bizhi;
};
int cmp(node a,node b)
{
    return a.bizhi>b.bizhi;
}
int main()
{
    node a[1005];
    int n;
    double d,sum=0;
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].liang;
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i].jia;
        a[i].bizhi=a[i].jia/a[i].liang;
    }
    sort(a,a+n,cmp);
    for(int i=0;d;i++)
    {
        if(d>a[i].liang)
        {
            d-=a[i].liang;
            sum+=a[i].jia;
        }
        else
        {
            sum+=d*a[i].bizhi;
            d=0;
        }
    }
    printf("%.2lf\n",sum);
    return 0;
}
