#include <iostream>
#include <stdio.h>
#define N 1999
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
        int n;cin>>n;
        if(!s[n])
        {
            printf("%d\n",n);
            continue;
        }
        for(int i=1;;i++)
        {
            if(!s[n+i]&&n+i<N)
            {
                printf("%d\n",n+i);
                break;
            }
            if(!s[n-i]&&n-i>0)
            {
                printf("%d\n",n-i);
                break;
            }
        }
    }
    return 0;
}
