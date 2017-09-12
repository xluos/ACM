#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[10005],ch;
    queue<char>qu;
    int i=0,flag=1;
    while(~scanf("%c",&ch))
    {
        if(ch=='-')cout<<'-';
        else if(ch=='+'||ch=='.');
        else if(ch>='0'&&ch<='9')
        {
            qu.push(ch);
        }
        else
        {
            break;
        }
    }
    int ans;
    cin>>ans;
    flag+=ans;
    if(flag<1)
    {
        for(int i=0; i<=-flag; i++)
        {
            if(i==1)cout<<'.';
            cout<<'0';
        }
        while(!qu.empty())
        {
            cout<<qu.front();
            qu.pop();
        }
    }
    else
    {
        while(!qu.empty())
        {
            if(i==flag)cout<<'.';
            cout<<qu.front();
            qu.pop();
            i++;
        }
        for(; i<flag; i++)
        {
            cout<<'0';
        }
    }
    cout<<endl;
    return 0;
}
