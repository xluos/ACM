#include <iostream>

using namespace std;
int myfind(int n,int m,int a[])
{
    for(int i=0;i<n;i++)
    {
        if(a[i] == m)
            return i+1;
    }
    return -1;
}
int main()
{
    int n,m = -1,a[1005];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    cout<<myfind(n,m,a)<<endl;
    return 0;
}
