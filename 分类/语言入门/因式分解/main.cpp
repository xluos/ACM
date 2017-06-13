#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
/*int judge(int n)
{
    int i=0;
    for(i=2;i<sqrt(n)+1;i++)
        if(!n%i)return 0;
    return 1;
}
int main()
{
    int z[]={2,3,5,7,11,13,17,19,23,
            29,31,37,41,43,47,53,59,
            61,67,71,73,79,83,89,97
            };
    int w;cin>>w;
    while(w--)
    {
        int a,b,count=0,sum=1;
        cin>>a>>b;
        for(int i=2;i<=a;i++)
        {
            sum*=i;cout<<sum<<endl;
            for(int j=0;sum%z[j]==0;)
            {
                if(z[j]==b)count++;
                if(sum%z[j]==0)sum/=z[j];
                else j++;
            }
            if(sum==0)sum=1;
        }/*
        for(int i=1;i<=a;i++)
        {
            sum*=i;

            for(;sum%2==0;sum/=2)if(b==2)count++;
            if(!sum)sum=1;
        }
        for(int j=1;!judge(sum);)
        {
            if(z[j]==b)count++;
            if(sum%z[j]==0)sum/=z[j];
            else j++;
        }
        cout<<sum<<endl;
        cout<<count<<endl;
    }
    return 0;
}
*/
int main()
{
    int w;
    cin>>w;
    while(w--)
    {
        int m,n,t,sum=0;
        cin>>n>>m;
        while(n)
        {
            n=n/m;
            sum+=n;
        }
        cout<<sum<<endl;
    }
}
