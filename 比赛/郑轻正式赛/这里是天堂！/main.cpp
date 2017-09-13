#include <iostream>

using namespace std;
int C(int n,int m)
{
    if(n>m)return 0;
    if(n==m)return 1;
    if(n>m/2.0)n=m-n;
    double sum=1;
    for(int i=m,j=1;j<=n;j++,i--)
        sum=sum*i/j;
    return sum;
}
int gongye(int a,int b)
{
    if(a<b){int t=a;a=b;b=t;}
    return b==0?a:gongye(b,a%b);
}
int main()
{
    int n,m,k,a,b;
    int w;cin>>w;
    while(w--)
    {
        cin>>n>>m>>k>>a>>b;
        if(a>n||b>m||(k!=a+b)&&k<=m+n)
            cout<<"0 1"<<endl;
        else
        {
            if(k>m+n)
            k=m+n;
            int fm=C(k,n+m),fz=C(a,n)*C(b,m);
            int gy=gongye(fz,fm);
            cout<<fz/gy<<' '<<fm/gy<<endl;
        }
    }
    return 0;
}
