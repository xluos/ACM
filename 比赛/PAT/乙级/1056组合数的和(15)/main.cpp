#include <iostream>

using namespace std;

int main()
{
    int n,sum=0,ans;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ans;
        sum+=ans*11*(n-1);
    }
    cout<<sum;
    return 0;
}
