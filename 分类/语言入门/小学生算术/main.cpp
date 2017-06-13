#include <iostream>
#include <stdio.h>
using namespace std;
void itoa(int a,char *s)
{
    int i,j;
    for(i=0;a;i++)
    {
        s[i]=a%10;
        a/=10;
    }
    s[i]='\0';
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m),n+m)
    {
        char a[5],b[5],c[6];
        int count=0;
        itoa(n,a);
        itoa(m,b);
        itoa(n+m,c);
        for(int i=0;i<3;i++)
        {
            if(c[i]<a[i]+b[i])
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
