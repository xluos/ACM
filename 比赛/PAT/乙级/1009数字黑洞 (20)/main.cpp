#include <bits/stdc++.h>

using namespace std;
int cmp(char a,char b)
{
    return a>b;
}
void zhuanhuan(char s[],int *a,int *b)
{
    sort(s,s+4,cmp);
    sscanf(s,"%d",a);
    sort(s,s+4);
    sscanf(s,"%d",b);
}
int main()
{
    int a=0,b=0,n;
    char s[10];
    cin>>n;
    sprintf(s,"%04d",n);
    zhuanhuan(s,&a,&b);
    while(1)
    {
        printf("%04d - %04d = %04d\n",a,b,a-b);
        if(a-b==6174||a==b)
            break;
        sprintf(s,"%04d",a-b);
        zhuanhuan(s,&a,&b);
    }
    return 0;
}
