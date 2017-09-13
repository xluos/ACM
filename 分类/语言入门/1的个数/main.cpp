#include <iostream>

using namespace std;

int main()
{
    int w;cin>>w;
    while(w--)
    {
        int n,count=0;
        cin>>n;
        for(;n;n>>=1)
        {
            if(n&1)
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
