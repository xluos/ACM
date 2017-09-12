#include <iostream>

using namespace std;

int main()
{
    int w;cin>>w;
    while(w--)
    {
        int n,m,t=0,ans;
        cin>>n>>m;
        ans=n;
        while(ans)
        {
            ans+=t;
            t=ans%m;
            ans/=m;
            n+=ans;

        }
        cout<<n<<endl;
    }
    return 0;
}
