#include <iostream>
#include <stdio.h>
#define N 1005
using namespace std;
int s[N]={0};
void init ()
{
    s[0]=s[1]=1;
    int i,j;
    for(i=2;i<N/2+1;i++)
    {
        for(j=i+i;j<N;j+=i)
            s[j]=1;
    }
}
int main()
{
    init();
    int w;cin>>w;
    while(w--)
    {
        int n,sum=0,ans;
        cin>>n;
        while(n--)
        {
            cin>>ans;
            if(!s[ans])
                sum+=ans;
        }
        cout<<sum<<endl;
    }
    return 0;
}
