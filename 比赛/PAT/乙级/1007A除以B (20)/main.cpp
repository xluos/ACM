#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[1005],q[1005];
    int b,r,ans,j=0,i=0;
    scanf("%s %d",a,&b);
    int l=strlen(a);
    ans=a[0]-'0';i=1;
    do
    {
        if(ans<b&&i<l)
        {
            ans=ans*10+a[i++]-'0';
        }
        q[j++]=ans/b;
        ans%=b;
    }while(i<l);
    for(int i=0;i<j;i++)
        printf("%c",q[i]+'0');
    printf(" %d\n",ans);
    return 0;
}
