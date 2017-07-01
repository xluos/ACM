#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[1005],q[1005];
    int b,r,ans,j=0;
    scanf("%s %d",a,&b);
    int l=strlen(a);
    ans=a[0]-'0';
    for(int i=1;i<l;)
    {
        if(ans<b)
        {
            ans=ans*10+a[i++]-'0';
        }
        q[j++]=ans/b;
        ans%=b;
    }
    for(int i=0;i<j;i++)
        printf("%c",q[i]+'0');
    printf(" %d\n",ans);
    return 0;
}
