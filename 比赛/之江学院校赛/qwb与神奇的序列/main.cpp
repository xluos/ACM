#include <bits/stdc++.h>
#define D 1000000000
using namespace std;
long long int a[10] ;
void Init()
{
    a[0] = 3;
    for(int i=1;i<=9;i++)
    {
        a[i] = 1;
        for(int j=1;j<=10;j++)
            a[i] = (a[i]*a[i-1])%D;
    }
    for(int i=0;i<10;i++)
        cout<<a[i]<<endl;
}
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
unsigned long long pow_3(int y)
{
    char s[66];
    unsigned long long sum=1,ans;
    sprintf(s,"%d",y);
    int l=strlen(s);
    for(int i=l-1;i>=0;i--)
    {
        ans=pow(l-i,s[i]-'0');
        sum=(sum*ans)%D;
    }
    return sum%D;
}

int main()
{
    Init();
    unsigned long long sum=1;
    int a,b,n;
    while(~scanf("%d %d %d",&a,&b,&n))
    {
        int ans=a+b;
        sum=ans*(((pow_3(n)+1)/2)%100000000);
        printf("%lld\n",sum%100000000);
    }
    return 0;
}
/*
#include <bits/stdc++.h>
#define D 1000000000
#define D1 100000000
using namespace std;
long long int a[10];
void Init()
{
    a[0] = 3;
    for(int i=1;i<=9;i++)
    {
        a[i] = 1;
        for(int j=1;j<=10;j++)
            a[i] = (a[i]*a[i-1])%D;
    }
    for(int i=0;i<10;i++)
        cout<<a[i]<<endl;
}
long long int f(int n)
{
//    int k=0;
//    long long int sum = 1;
//    while(n)
//    {
//        int t = n%10;
//        n=n/10;
//        for(int i=0;i<t;i++)
//            sum = (sum*a[k])%D;
//        k++;
//    }
//    return sum;
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    //cout<<s<<endl;
    int len = s.length();
    long long sum = 1;
    for(int i=0;i<len;i++)
    {
        for(int j = 0;j < (s[i] - '0');j++)
            sum = (sum *a[len-i-1])%D;
    }
    return sum;
}
int main()
{
    Init();
    long long int a,b,n,ans;
    while(~scanf("%lld %lld %lld",&a,&b,&n))
    {
        ans=a+b;
        ans =((f(n)+1)/2*ans)%D1;
        printf("%lld\n",ans%D1);
    }
    return 0;
}*/
