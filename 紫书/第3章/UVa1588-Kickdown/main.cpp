#include <bits/stdc++.h>

using namespace std;
string s,s2;
int cmp(string &s,string &s2,int p,int q,int n)
{
    for(int i=0;i<n;i++)
    {
        if(s[p+i]+s2[q+i]>'2'+'1')
            return 0;
    }
    return 1;
}
int main()
{

    while(cin>>s>>s2)
    {
        int l=s.size(),l2=s2.size();
        int minn=l+l2;
        for(int i=0;i<l;i++)
            if(cmp(s,s2,i,0,min(l-i,l2))) minn=min(max(i+l2,l),minn);
        for(int i=0;i<l2;i++)
            if(cmp(s2,s,i,0,min(l2-i,l))) minn=min(max(i+l,l2),minn);
        cout<<minn<<endl;
    }
    return 0;
}
