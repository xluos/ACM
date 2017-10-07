#include <bits/stdc++.h>
#define ull  long long
using namespace std;
ull gcd(ull a,ull b)
{
    return !(a%b)?b:gcd(b,a%b);
}
void huajian(ull fz,ull fm)
{
    ull gy,flag=0;
    if(fz<0||fm<0)
    {
        if(!(fz<0&&fm<0))
        {
            printf("(-");
            flag=1;
        }
        if(fz<0)fz=-fz;
        if(fm<0)fm=-fm;
    }
    gy=gcd(fz,fm);
    fz/=gy;fm/=gy;

    if(!fz)
    {
        printf("0");
    }
    else if(fm==1)
    {
        printf("%lld",fz);
    }
    else if(fz>fm)
    {
        printf("%lld %lld/%lld",fz/fm,fz%fm,fm);
    }
    else
        printf("%lld/%lld",fz%fm,fm);
    if(flag)
        printf(")");
}
int main()
{
    ull a,b,c,d;
    scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
    huajian(a,b);
    printf(" + ");
    huajian(c,d);
    printf(" = ");
    huajian(a*d+b*c,b*d);
    printf("\n");
    huajian(a,b);
    printf(" - ");
    huajian(c,d);
    printf(" = ");
    huajian(a*d-b*c,b*d);
    printf("\n");
    huajian(a,b);
    printf(" * ");
    huajian(c,d);
    printf(" = ");
    huajian(a*c,b*d);
    printf("\n");
    huajian(a,b);
    printf(" / ");
    huajian(c,d);
    printf(" = ");
    if(!c)
        printf("Inf");
    else
        huajian(a*d,b*c);
    printf("\n");
    return 0;
}
