#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    set<int>se;
    while(n--)
    {
        int ans;
        cin>>ans;
        se.insert(ans);
    }
    set<int>::iterator it=se.begin();
    it++;it++;
    if(se.size()<3)
        cout<<-1<<endl;
    else
        cout<<*(it)<<endl;
    return 0;
}
