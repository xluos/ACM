#include <iostream>
#include <bits/stdc++.h>
#define D 1000000007
using namespace std;
int a[] = {1,3,59049,886041711,56888193,895629451,916902199,64935414,769346453,280212335,235939645,368819707};
unsigned long long pow(int l,int n)
{
    unsigned long long sum=1;
    while(n--)
    {
        sum*=a[l];
        sum%=D;
    }
    if(sum<D)
    return sum;
    return sum%D;
}
int main()
{
    int T;scanf("%d",&T);
    char s[20];
    while(T--)
    {

        int n;
        int x,y;
        unsigned long long sum=1,ans;
        scanf("%d",&n);
        if(n==0||n==1||n==2||n==3||n==4)
        {
            printf("%d\n",n);
            continue;
        }
        x = n%3;
        y=n/3;
        if(x==1)
        {
            sprintf(s,"%d",y-1);
            int l=strlen(s);
            for(int i=l-1;i>=0;i--)
            {
                ans=pow(l-i,s[i]-'0');
                sum=(sum*ans)%D;
            }
            sum=(sum*4)%D;
        }
        else if(x==2)
        {
            sprintf(s,"%d",y);
            int l=strlen(s);
            for(int i=l-1;i>=0;i--)
            {
                ans=pow(l-i,s[i]-'0');
                sum=(sum*ans)%D;
            }
            sum=(sum*2)%D;
        }
        else
        {
            sprintf(s,"%d",y);
            int l=strlen(s);
            for(int i=l-1;i>=0;i--)
            {
                ans=pow(l-i,s[i]-'0');
                sum=(sum*ans)%D;
            }
            sum=sum%D;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
