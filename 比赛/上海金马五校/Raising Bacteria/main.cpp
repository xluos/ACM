#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int sum=0;
        while(n)
        {
            if(n&1)
                sum++;
            n>>=1;
        }
        printf("%d\n",sum);
    }
    return 0;
}
