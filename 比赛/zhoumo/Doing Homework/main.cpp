#include <iostream>

using namespace std;
struct node{
    string s;
    int l,r,c;
};
bool cmp(node a,node b)
{
    if(a.r == b.r)
    {
        if(a.l == b.l)
        {
            return a.s<b.s;
        }
        return a.l<b.l;
    }
    return a.r<b.r;
}
int main()
{
    node N[20];
    int w;
    cin>>w;
    while(w--)
    {
        int n,a[3000];
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>N[i].s>>N[i].r>>N[i].c;
            N[i].l = N[i].r - N[i].c;
        }
        sort(N,N+n,cmp);
        int t=0;
        for(int i=0;i<n;i++)
        {
            a[1000+N[i].l]++;
            a[1000+N[i].r]--;
        }
        for(int i=1;i<3000;i++)
        {
            a[i] += a[i-1];
            if(a[i] > 1) t+=a[i]-1;
        }
        cout<<t<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<N[i].s<<endl;
        }
    }
    return 0;
}
