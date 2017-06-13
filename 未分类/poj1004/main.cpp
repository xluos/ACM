#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    double sum=0,ans;
    for(int i=0;i<12;i++)
    {
        cin>>ans;
        sum+=ans;
    }
    printf("$%.2lf\n",sum/12);
    return 0;
}
