#include <iostream>

using namespace std;

int main()
{
    int w;cin>>w;
    while(w--)
    {
        int a,b,c,sum;
        cin>>a>>b>>c;
        cout<<a*b+(a/30*c)<<endl;
    }
    return 0;
}
