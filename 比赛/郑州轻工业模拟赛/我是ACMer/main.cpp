#include <iostream>

using namespace std;

int main()
{
    int w;cin>>w;
    while(w--)
    {
        int n;cin>>n;
        n%=10;
        for(int i=0;i<n;i++)
        cout << "I am a good ACMer" << endl;
        cout<<endl;
    }

    return 0;
}
