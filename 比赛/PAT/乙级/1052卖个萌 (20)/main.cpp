#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string>ve[3];
    for(int k=0; k<3; k++)
    {
        string s;
        getline(cin,s);
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='[')
            {
                for(int j=i+1;j<s.size(); j++)
                {
                    if(s[j]==']')
                    {
                        ve[k].push_back(s.substr(i+1,j-i-1));
                        break;
                    }
                }
            }
        }
    }
    int n,m[5];
    cin>>n;
    int hand=ve[0].size(),eye=ve[1].size(),mouth=ve[2].size();
    while(n--)
    {
        for(int i=0; i<5; i++)
        {
            cin>>m[i];
            m[i]--;
        }
        if(m[0]<hand&&m[1]<eye&&m[2]<mouth&&m[3]<eye&&m[4]<hand&&m[0]>=0&&m[1]>=0&&m[2]>=0&&m[3]>=0&&m[4]>=0)
        {
            cout<<ve[0][m[0]]<<'('<<ve[1][m[1]]<<ve[2][m[2]]<<ve[1][m[3]]<<')'<<ve[0][m[4]]<<endl;
        }
        else
        {
            cout<<"Are you kidding me? @\\/@"<<endl;
        }
    }
    return 0;
}
