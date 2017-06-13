#include <iostream>
#include <cstdio>


using namespace std;
int abs(int a)
{
    if(a<0)
        return -a;
    return a;
}
int gy(int a,int b)
{
    return b==0?a:gy(b,a%b);
}
int main()
{
    int a,b,c,d;
    while(~scanf("%d/%d%d/%d",&a,&b,&c,&d))
    {
        int fz=a*d+c*b;
        int fm=b*d;
        if(fz==0)
            printf("0\n");
        else
        {
            int g=abs(gy(fz,fm));
            fz=fz/g;
            fm=fm/g;
            if(fm==1)
                printf("%d\n",fz);
            else
                printf("%d/%d\n",fz,fm);
        }

    }
    return 0;
}
