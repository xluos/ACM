#include <bits/stdc++.h>

using namespace std;
int judeg(int a[])
{
    int sum=0;
    for(int i=0;i<300;i++)
        if(a[i])sum+=a[i];
    return sum;
}
int main()
{
    int mp[300]={0},sum=0,l,l2;
    char s[1005],s2[1005];
    scanf("%s %s",s,s2);
    l=strlen(s);sum=l2=strlen(s2);
    for(int i=0;i<l2;i++)
    {
        mp[s2[i]]++;
    }
    for(int i=0;i<l;i++)
    {
        if(mp[s[i]])
        {
            sum--;
            mp[s[i]]--;
        }
    }
    if(!judeg(mp))
    {
        printf("Yes %d\n",l-l2);
    }
    else
    {
        printf("No %d\n",judeg(mp));
    }
    return 0;
}
/**
ppRYYGrrYBR2258
YrR8RrY
*/
