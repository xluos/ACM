#include <bits/stdc++.h>

using namespace std;
void my_itoa(int n,int r)
{
    if(n==0)printf("0");
    stack<int>st;
    while(n)
    {
        st.push(n%r);
        n/=r;
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}
int main()
{
    int a,b,d;
    cin>>a>>b>>d;
    my_itoa(a+b,d);
    return 0;
}
