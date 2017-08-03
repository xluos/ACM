#include <bits/stdc++.h>

using namespace std;
char mirrored(char ch)
{
    char s[]="A   3  HIL JM O   2TUVWXY5";
    char s2[]=" 1SE Z  8 ";
    if(ch>='A'&&ch<='Z') return s[ch-'A'];
    else return s2[ch-'0'];
}
int main()
{
    char s[50];
    while(~scanf("%s",s))
    {
        int p=1,m=1,l=strlen(s);
        for(int i=0;i<(l+1)/2;i++)
        {
            if(s[i]!=s[l-1-i]) p=0;
            if(s[i]!=mirrored(s[l-1-i])) m=0;
        }
        printf("%s",s);
        if(m==0)
        {
            if(p==0)
                printf(" -- is not a palindrome.\n\n");
            else
                printf(" -- is a regular palindrome.\n\n");
        }
        else
        {
            if(p==0)
                printf(" -- is a mirrored string.\n\n");
            else
                printf(" -- is a mirrored palindrome.\n\n");
        }
    }
    return 0;
}
