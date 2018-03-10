#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    scanf("%lld",&n);
    char s[100];
    sprintf(s,"%llx",n);
    for(int i=0;s[i];i++)
    {
        if(s[i]>='a') s[i] -= 'a'-'A';
        putchar(s[i]);
    }
    printf("\n");
    return 0;
}
