#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s,s2;
    while(cin>>s>>s2)
    {
        int flag=1;
        int l=s.length();
        int a[26]={0},b[26]={0};
        for(int i=0;i<l;i++)
        {
            a[s[i]-'A']++;
            b[s2[i]-'A']++;
        }
        sort(a,a+26);
        sort(b,b+26);
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                flag=0;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
