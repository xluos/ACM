#include <iostream>

using namespace std;

int main()
{
    int sum = 0,maxx = -99999,minn = 99999,a[10005];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        minn = minn>a[i]?a[i]:minn;
        maxx = maxx<a[i]?a[i]:maxx;
    }
    cout<<maxx<<'\n'<<minn<<'\n'<<sum<<endl;
    return 0;
}
