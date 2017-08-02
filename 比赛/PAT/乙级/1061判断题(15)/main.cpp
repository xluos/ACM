#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,da[105],f[105];
    cin>>n>>m;
    for(int i=0;i<m;i++) cin>>f[i];
    for(int i=0;i<m;i++) cin>>da[i];
    for(int i=0;i<n;i++)
    {
        int ans,sum=0;
        for(int j=0;j<m;j++)
        {
            cin>>ans;
            if(ans==da[j]) sum+=f[j];
        }
        cout<<sum<<endl;
    }
    return 0;
}
