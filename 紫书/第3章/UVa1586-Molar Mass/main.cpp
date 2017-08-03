#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char,double>mp;
    mp['C']=12.01;
    mp['H']=1.008;
    mp['O']=16;
    mp['N']=14.01;
    int n;cin>>n;
    string s;
    while(n--)
    {
        double sum=0,ans=0;
        int k=0;
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                k=k*10+s[i]-'0';
            }
            else
            {
                if(!k)k=1;
                sum+=ans*k;
                k=0;
                ans=mp[s[i]];
            }
        }
        if(!k)k=1;
        sum+=ans*k;
        printf("%.3lf\n",sum);
    }
    return 0;
}
