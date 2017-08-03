#include <bits/stdc++.h>
#define NO 4294967295
using namespace std;
string s="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
    char ch;
    while(~scanf("%c",&ch))
    {
        int k=0;
        for(k=0;s[k]&&s[k]!=ch;k++);
        if(!s[k]) cout<<ch;
        else cout<<s[k-1];
    }
    return 0;
}
