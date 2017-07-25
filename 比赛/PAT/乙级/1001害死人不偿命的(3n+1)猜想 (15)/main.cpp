#include <iostream>

using namespace std;
int _3n(int n)
{
    if(n==1) return 0;
    if(n&1) return _3n((n*3+1)/2)+1;
    else return _3n(n/2)+1;
}
int main()
{
    int n;
    cin>>n;
    cout<<_3n(n)<<endl;
    return 0;
}
