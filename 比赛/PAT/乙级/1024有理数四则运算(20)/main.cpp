#include <bits/stdc++.h>

using namespace std;
int gcd(int a,int b)
{
    return !(a%b)?b:gcd(b,a%b);
}
void huajian(int fz,int fm)
{
    int gy,flag=0;
    if(fz<0||fm<0)
    {
        if(fz<0)fz=-fz;
        if(fm<0)fm=-fm;
        printf("(-");
        flag=1;
    }
    gy=gcd(fz,fm);
    fz/=gy;fm/=gy;

    if(!fz)
    {
        printf("0");
    }
    else if(fm==1)
    {
        printf("%d",fz);
    }
    else if(fz>fm)
    {
        printf("%d %d/%d",fz/fm,fz%fm,fm);
    }
    else
        printf("%d/%d",fz%fm,fm);
    if(flag)
        printf(")");
}
int main()
{
    int a,b,c,d;
    scanf("%d/%d %d/%d",&a,&b,&c,&d);
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
