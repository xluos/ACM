#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,maxx=0;
    int x1,y1,x2,y2;
    map<pair<int,int>,int>mp;
    pair<int,int>pr;
    cin>>n;
    while(n--)
    {
        cin>>x1>>y1>>x2>>y2;
        mp[make_pair(x2-x1,y2-y1)]++;
    }
    for(map<pair<int,int>,int>::iterator it=mp.begin();it!=mp.end();it++)
    {
        if(it->second>maxx)
        {
            maxx=it->second;
            pr=it->first;
        }
    }
    cout<<pr.first<<' '<<pr.second<<endl;
    return 0;
}
