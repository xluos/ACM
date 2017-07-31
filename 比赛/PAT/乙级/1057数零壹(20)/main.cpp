#include <bits/stdc++.h>

using namespace std;

int main()
{
    char ch;
    int _0=0,_1=0,sum=0;
    while(~scanf("%c",&ch))
    {
        if(ch>='a'&&ch<='z') sum+=ch-'a'+1;
        if(ch>='A'&&ch<='Z') sum+=ch-'A'+1;
    }
    while(sum)
    {
        if(sum&1) _1++;
        else _0++;
        sum>>=1;
    }
    cout<<_0<<' '<<_1<<endl;
    return 0;
}
