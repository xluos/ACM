#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int mov(int x)
{
    if(x<0)x=-x;
    return x;
}
int gy(int a ,int b )
{
    int t;
    a=mov(a);b=mov(b);
    if(a==0||b==0)return 0;
    if(a<b)
    {t=a;a=b;b=t;}
    while(a%b)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return b;
}
int main()
{
    int w,u,s,d,ans;cin>>w;getchar;
    u=s=d=0;ans=w;
    while(w--)
    {
        char a;
        cin>>a;
        if(a=='U')u++;
        if(a=='S')s++;
        if(a=='D')d++;
    }
    int x=gy(u,ans);
    double t=fabs(0.5-u*1.0/ans);
    if(s)printf("Bingo\n");
    else if(t<0.003)printf("%d/%d\n",u/x,ans/x);
    else printf("Fail\n");
    return 0;
}
