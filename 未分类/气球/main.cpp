#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int q[100006];
int main()
{
    int w;
    while(cin>>w,w)
    {
        int maxx;
        memset(q,0,sizeof(q));
        for(int i=0;i<w;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            q[a]++;q[b+1]--;
        }
        cout<<q[1];
        for(int i=2;i<=w;i++)
        {
            q[i]+=q[i-1];
            printf(" %d",q[i]);
        }
        printf("\n");
    }
    return 0;
}
