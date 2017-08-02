#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string,int>mp;
    vector<string>ve;
    int n,k,m,flag=1;
    cin>>n>>k>>m;
    m--;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        ve.push_back(s);
    }
    for(int i=m,t=0;i<n;i++,t++)
    {
        if(i==m||t==k)
        {
            for(;mp[ve[i]]&&i<n;i++);
            if(i==n) break;
            mp[ve[i]]=1;
            cout<<ve[i]<<endl;
            t=0;flag=0;
        }
    }
    if(flag) cout<<"Keep going..."<<endl;
    return 0;
}
