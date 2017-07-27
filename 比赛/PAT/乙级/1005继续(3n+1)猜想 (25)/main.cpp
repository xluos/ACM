#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map<int ,int>mp;
int _3n(int n)
{
    if(n==1) return 1;
    if(n&1)
    {
        if(!mp[(n*3+1)/2]) mp[(n*3+1)/2]=_3n((n*3+1)/2);
        return mp[(n*3+1)/2]+1;
    }
    else
    {
        if(!mp[n/2]) mp[n/2]=_3n(n/2);
        return mp[n/2]+1;
    }
}
int main()
{
    int n,a[105],flag=1;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]=0;
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--)
    {
        _3n(a[i]);
    }
    for(map<int,int>::reverse_iterator it=mp.rbegin();it!=mp.rend();it++)
    {
        //cout<<"key:"<<it->first<<' '<<"ve:"<<it->second<<endl;
        if(it->second==0)
        {
            if(flag)
            {
                cout<<it->first;
                flag=0;
            }
            else
            {
                cout<<' '<<it->first;
            }
        }
    }
    cout<<endl;
    return 0;
}
