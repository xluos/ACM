#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin>>n;
    while(n--)
    {

        string mins="Z";
        char minch='Z';
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]<minch) {minch=s[i];}
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==minch)
            {
                string ans=s.substr(i,s.length()-i)+s.substr(0,i);
                if(mins>ans) mins=ans;
            }
        }
        cout<<mins<<endl;
    }
    return 0;
}
