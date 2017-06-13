#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
struct ren{
    string name;
    int dz;
};
int main()
{
    string s;
    set<string>se,name;
    ren r[10006];
    int sum=0,z,n;cin>>n;
    while(n--)
    {
        cin>>s;
        se.insert(s);
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>r[i].name>>r[i].dz;
        sum+=r[i].dz;
    }
    sum /=n;
    for(int i=0;i<n;i++)
    {
        if(r[i].dz>sum&&!se.count(r[i].name))
            name.insert(r[i].name);
    }
    set<string>::iterator it;
    if(!name.empty())
    for(it=name.begin();it!=name.end();it++)
    {
        cout<<*it<<endl;
    }
    else
        cout<<"Bing Mei You"<<endl;
    return 0;
}
