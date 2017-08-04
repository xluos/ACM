#include <bits/stdc++.h>
using namespace std;
int judeg(string &s,int n)
{
    int l=s.size();
    for(int i=n;i<=l-n;i+=n)
    {
        if(s.substr(0,n)!=s.substr(i,n))
            return 0;
    }
    return 1;
}
int main()
{
    int n;
    string s;
    cin>>n;getchar();
    while(n--)
    {
        cin>>s;
        int l=s.size();
        for(int i=1;i<=l;i++)
        {
            if(!(l%i)&&judeg(s,i))
            {
                printf("%d%s",i,n?"\n\n":"\n");
                break;
            }
        }
    }
    return 0;
}
