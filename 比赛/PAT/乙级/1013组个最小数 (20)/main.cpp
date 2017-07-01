#include <iostream>

using namespace std;

int main()
{
    int mp[10]={0};
    for(int i=0;i<10;i++)
    {
        cin>>mp[i];
    }
    for(int i=1;i<10;i++)
    {
        if(mp[i])
        {
            mp[i]--;
            cout<<i;
            break;
        }
    }
    for(int i=0;i<10;i++)
    {
        if(mp[i])
        {
            for(int j=0;j<mp[i];j++)
                cout<<i;
        }
    }
    cout<<endl;
    return 0;
}
