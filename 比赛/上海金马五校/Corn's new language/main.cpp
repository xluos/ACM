#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int pipei(char s[])
{
    int l=strlen(s);
    if(l%2)return 0;
    stack<char>st;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='(')
            st.push('(');
        else
        {
            if(!st.empty())
                st.pop();
            else
                return 0;
        }
    }
    if(!st.empty())
        return 0;
    return 1;
}
int shendu(char s[])
{
    int l=strlen(s);
    stack<char>st;
    st.push('(');
    for(int i=1;i<l;i++)
    {
        if(s[i]=='(')
        {
            if(st.top()==')')
                st.pop();
            else
                st.push('(');
        }
        else
        {
            st.push(')');
        }
    }
    return st.size()/2;
}
int main()
{
    char s[110];
    while(~scanf("%s",s))
    {
        if(pipei(s))
        {
            printf("YES %d\n",shendu(s));
        }
        else
            printf("NO\n");
    }
    return 0;
}
