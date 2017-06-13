#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char s1[10],s2[10];
    int a=1;
    while(~scanf("%s %s",s1,s2))
    {
        printf("Case %d: ",a++);
        if(s1[1]=='#')
        {
            if(s1[0]=='G')s1[0]='A';
            else s1[0]+=1;
            s1[1]='b';
            printf("%s %s\n",s1,s2);
        }
        else if(s1[1]=='b')
        {
            if(s1[0]=='A')s1[0]='G';
            else s1[0]-=1;
            s1[1]='#';
            printf("%s %s\n",s1,s2);
        }
        else
            printf("UNIQUE\n");
    }
    return 0;
}
