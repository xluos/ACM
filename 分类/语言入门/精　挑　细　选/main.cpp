#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct gg{
    int l,d,bh;
};
bool cmp(gg a,gg b)
{
    if(a.l==b.l)
    {
        if(a.d==b.d)
            return a.bh>b.bh;
        else
            return a.d<b.d;
    }
    else
        return a.l>b.l;
}
int main()
{
    int w;cin>>w;
    while(w--)
    {
        gg n[1005];
        int m;cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>n[i].l>>n[i].d>>n[i].bh;

        }
        sort(n,n+m,cmp);
        cout<<n[0].bh<<endl;
    }
    return 0;
}
