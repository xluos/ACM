#include <bits/stdc++.h>

using namespace std;
string s[1000005],ans;
char str[1000005];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m,k,maxx=0,sizee;
    cin>>n;
    set<int>se;
    while(n--)
    {
        cin>>ans>>m;
        sizee=ans.size();
        for(int i=0;i<m;i++)
        {
            cin>>k;se.insert(k);
            if(ans>s[k])s[k]=ans;
            if(k+sizee-1>maxx)maxx=k+sizee-1;
        }
    }
    for(set<int>::iterator it=se.begin();it!=se.end();it++)
    {
            copy(s[*it].begin(),s[*it].end(),str+*it-1);
    }
    for(int i=0;i<maxx;i++)
    {
        if(str[i]<'a')cout<<'a';
        else cout<<str[i];
    }
    cout<<endl;
    return 0;
}
