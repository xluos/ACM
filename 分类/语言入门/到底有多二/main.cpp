#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

double _2(char s[])
{
    int l=strlen(s),k=0,sum=0;
    if(s[0]=='-')k=1;
    for(int i=k;i<l;i++)
        if(s[i]=='2')sum++;
    double n=1.0*sum/(l-k);
    if(k)n *= 1.5;
    if(!((s[l-1]-'0')%2))n *= 2;
    return n;

}
int main()
{
    char s[55];
    scanf("%s",s);
    printf("%.2lf%%",_2(s)*100);
    return 0;
}
