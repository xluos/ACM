#include <iostream>

using namespace std;

int main()
{
    int k=12;
    double x,sum=0;
    while(k--)
    {
        cin>>x;
        sum+=x;
    }
    cout<<sum/12<<endl;
    return 0;
}
