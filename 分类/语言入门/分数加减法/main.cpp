#include <iostream>
#include <stdio.h>
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
    int a,b,c,d;
    char o;
    while(~scanf("%d/%d%c%d/%d",&a,&b,&o,&c,&d))
    {
        int n=b*d,x=a*d,y=c*b,m;
        switch(o)
        {
            case '+' : m=x+y;break;
            case '-' : m=x-y;break;
        }
        int t=gy(m,n);
        if(m!=0)
        {
            if(n/t==1)
                printf("%d\n",m/t);
            else
                printf("%d/%d\n",m/t,n/t);

        }
        else
            printf("0\n");
    }
    return 0;
}
