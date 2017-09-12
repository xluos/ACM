#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int judge(char ch)
{
    if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
        return 1;
    return 0;
}
int main()
{
    char s[100005];
    int l,mybegin=0,myend;
    while(gets(s))
    {
        int l=strlen(s);
        for(int i=0; i<l; i++)
        {
            if(judge(s[i]))
            {
                for(int j=i;; j++)
                    if(!judge(s[j]))
                    {
                        reverse(s+i,s+j);
                        i=j;
                        break;
                    }
            }
        }
        puts(s);
    }
    return 0;
}
