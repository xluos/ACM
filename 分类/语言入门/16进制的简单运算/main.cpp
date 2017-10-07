#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int w;cin>>w;
    while(w--)
    {
        int a,b;
        char o;
        scanf("%x%c%x",&a,&o,&b);
        if(o=='+')
            printf("%o\n",a+b);
        else
            printf("%o\n",a-b);
    }
    return 0;
}
