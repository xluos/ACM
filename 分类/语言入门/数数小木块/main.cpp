#include <iostream>

using namespace std;
int num(int n)
{
    if(n==1)
        return 1;
    return (num(n-1)+(n+1)*n/2);
}
int main()
{
    int w;cin>>w;
    while(w--)
    {
        int n;
        cin>>n;
        cout<<num(n)<<endl;
    }
    return 0;
}
