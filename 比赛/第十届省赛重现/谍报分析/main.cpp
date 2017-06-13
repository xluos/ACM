#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct nodee{
    string s;
    int num;
}node[510];
bool cmp(nodee a,nodee b)
{
    if(a.num==b.num)
        return a.s<b.s;
    return a.num>b.num;
}
int main()
{
    map<string,int>mp;
    int k=1;
    string s;
    while(cin>>s)
    {
        int len=s.size();
        if(s[len-1]==','||s[len-1]=='.')
        {
            s=s.substr(0,len-1);
        }
        int ans=mp[s];
        if(!ans)
        {
            mp[s]=k;
            node[k].s=s;
            node[k].num=1;
            k++;
        }
        else
        {
            node[ans].num++;
        }
    }
    sort(node,node+k,cmp);
    for(int i=0;i<10;i++)
    {
        cout<<node[i].s<<' '<<node[i].num<<endl;
    }
    return 0;
}
