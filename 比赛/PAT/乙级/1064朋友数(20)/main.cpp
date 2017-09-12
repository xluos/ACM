#include <bits/stdc++.h>

using namespace std;
int pys(int n)
{
    if(n) return n%10+pys(n/10);
    return 0;
}
int main()
{
    int n,ans,flag=0;
    set<int>se;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ans;
        se.insert(pys(ans));
    }
    cout<<se.size()<<endl;
    set<int>::iterator it=se.begin();
    cout<<*it;it++;
    for(;it!=se.end();it++)
        cout<<' '<<*it;
    return 0;
}
