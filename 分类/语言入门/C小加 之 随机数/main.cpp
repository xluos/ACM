#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

int main()
{
    int w;cin>>w;
    while(w--)
    {
        set<int>st;
        int n;cin>>n;
        while(n--)
        {
            int ans;
            cin>>ans;
            st.insert(ans);
        }
        cout<<st.size()<<endl;
        set<int>::iterator it=st.begin();
        cout<<*it;
        for(it++;it!=st.end();it++)
            printf(" %d",*it);
        cout<<endl;
    }
    return 0;
}
