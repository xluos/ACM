#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<string>st;
    string s;
    while(cin>>s) st.push(s);
    cout<<st.top();st.pop();
    while(!st.empty())
    {
        cout<<' '<<st.top();
        st.pop();
    }
    cout<<endl;
    return 0;
}
