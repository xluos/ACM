#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sum =0;
    int n;
    while(cin>>n)
    {
        sum = 0;
        for(int i=1;i<=n;i++)
            sum+=n/i;
        cout<<sum<<endl;
    }
    return 0;
}
