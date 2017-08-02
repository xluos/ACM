#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,n,flag=0;
    map<int,int>mp;
    vector<int>ve,dog;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        mp[a]=b;mp[b]=a;
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int ans;cin>>ans;
        ve.push_back(ans);
    }
    sort(ve.begin(),ve.end());
    for(int i=0;i<n;i++)
    {
        if(!binary_search(ve.begin(),ve.end(),mp[ve[i]]))
        {
            dog.push_back(ve[i]);
        }
    }
    cout<<dog.size()<<endl;
    for(int i=0;i<dog.size();i++)
    {
        printf("%05d%c",dog[i],i==dog.size()-1?'\n':' ');
    }
    return 0;
}
