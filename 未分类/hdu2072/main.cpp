#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    stringstream ss;
    set<string>se;
    while(getline(cin,s))
    {
        if(s=="#")
            break;
        ss<<s;
        while(ss>>s)
        {
            se.insert(s);
        }
        cout<<se.size()<<endl;
        se.clear();
        ss.clear();
    }
    return 0;
}
