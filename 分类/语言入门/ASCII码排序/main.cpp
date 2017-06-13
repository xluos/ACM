#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char a,b,c,t;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c;
        if(a>b)
        {
           t=a;
           a=b;
           b=t;
        }
        if(a>c)
        {
           t=c;
           c=a;
           a=t;
        }
        if(b>c)
        {
           t=c;
           c=b;
           b=t;
        }

        printf("%c %c %c\n",a,b,c);
    }
    return 0;
}
