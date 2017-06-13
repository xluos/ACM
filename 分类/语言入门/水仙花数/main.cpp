#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    char s[5];
    while(scanf("%s",s)&&s[0]!='0')
    {
        int a=s[0]-'0',b=s[1]-'0',c=s[2]-'0';
        int sum=a*100+b*10+c;
        if(a*a*a+b*b*b+c*c*c==sum)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
