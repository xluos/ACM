#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    int n;
    while(~scanf("%c",&ch))
    {
        if(ch=='@')
            break;
        scanf("%d",&n);
        getchar();
        for(int i=1;i<n;i++)
            printf(" ");
        printf("%c\n",ch);
        for(int i=2;i<n;i++)
        {
            for(int j=n-i-1;j>=0;j--)
                printf(" ");
            printf("%c",ch);
            int len=(i-1)*2-1;
            for(int j=0;j<len;j++)
                printf(" ");
            printf("%c\n",ch);
        }
        for(int i=0;i<n*2-1;i++)
            printf("%c",ch);
        printf("\n");
    }
    return 0;
}
