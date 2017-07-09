#include <bits/stdc++.h>

using namespace std;
string _12q[]= {"tret", "jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string _12h[]= {"tret", "tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

int stio(string s[],string ans)
{
    for(int i=0; i<13; i++)
    {
        if(s[i]==ans)
            return i;
    }
    return 0;
}
int main()
{
    int n,num,t=0;
    cin>>n;getchar();
    cin.clear();
    while(n--)
    {
        string ans;
        getline(cin,ans);
        stringstream ss(ans);
        if(ans[0]<='9'&&ans[0]>='0')
        {
            ss>>num;
            if(num<13)
                cout<<_12q[num]<<endl;
            else
            {
                t=num%13;
                num/=13;
                cout<<_12h[num];
                if(t)
                    cout<<' '<<_12q[t];
                cout<<endl;
            }

        }
        else
        {
            ss>>ans;
            t=0;
            num=stio(_12h,ans);
            while(ss>>ans)
            {t = stio(_12q,ans);}
            cout<<num*13+t<<endl;
            ss.clear();
        }
    }
    return 0;
}
