#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main()
{
    char ch;
    int p=0,a=0,sum=0;
    while(~scanf("%c",&ch))
    {
        if(ch=='P')p++;
        else if(ch=='A')a+=p;
        else
        {
            sum+=a;
            if(sum>MOD)
                sum%=MOD;
        }
    }
    cout<<sum<<endl;
    return 0;
}
