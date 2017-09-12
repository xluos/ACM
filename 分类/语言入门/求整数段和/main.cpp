#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a,b,t=1,sum=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++,t++)
    {
        if(!(t%6))
        {
            printf("\n");
            t=1;
        }
        printf("%5d",i);
        sum+=i;
    }
    printf("\nSum = %d\n",sum);
    return 0;
}
