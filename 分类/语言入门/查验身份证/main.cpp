#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int q[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char m[]={'1','0','X','9','8','7','6','5','4','3','2'},s[20];

int jianyan(char s[])
{
    int sum=0;
    for(int i=0;i<17;i++)
    {
        if(s[i]>'9'||s[i]<'0')return 0;
        sum += (s[i]-'0')*q[i];
    }
    sum %= 11;
    if(m[sum]==s[17])return 1;
    return 0;
}
int main()
{
    int w,k=1;
    cin>>w;
    while(w--)
    {
        scanf("%s",s);
        if(!jianyan(s))
        {printf("%s\n",s);k=0;}
    }
    if(k)printf("All passed\n");
    return 0;
}
