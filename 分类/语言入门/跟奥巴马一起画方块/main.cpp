#include <iostream>

using namespace std;

int main()
{
    double n;
    int m;
    char c;
    cin>>n>>c;
    m=n/2+0.5;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}
