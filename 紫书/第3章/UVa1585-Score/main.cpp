#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k,sum,n;
    string s;
    cin>>n;
    while(n--)
    {
        cin>>s;sum=0;k=1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='O')
            {
                sum+=k;
                k++;
            }
            else k=1;
        }
        cout<<sum<<endl;
    }
    return 0;
}
