#include <iostream>

using namespace std;

int main()
{
    int w;cin>>w;
    while(w--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        c>>=2;
        a>>=1;
        cout<<b-c+a<<endl;
    }
    return 0;
}
