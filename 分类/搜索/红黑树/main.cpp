#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
struct zuobiao{
    int z,y;
};
map<int,zuobiao>mp;
void zhong(int n)
{
    if(n==-1)
        return ;
    zhong(mp[n].z);
    cout<<n<<endl;
    zhong(mp[n].y);
}
int main()
{
    int w;
    cin>>w;
    while(w--)
    {

        int n,g,z,y;cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>g>>z>>y;
            mp[g].z=z;mp[g].y=y;
        }
        cin>>n;
        while(n--)
            cin>>z>>y;
        zhong(0);
    }
    return 0;
}
