#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int m[105][105];
    int n,W,H,S,T;
    while(scanf("%d",&n),n)
    {
        int maxx=0;
        memset(m,0,sizeof(m));
        scanf("%d %d",&W,&H);
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            m[x][y] = 1;
        }
        scanf("%d %d",&S,&T);
        for(int i=1;i<=W;i++)
        {
            for(int j=1;j<=H;j++)
            {
                m[i][j] += m[i][j-1];
            }
        }
        for(int i=T;i<=H;i++)
        {
            int t=1,sum=0;
            for(int j=1;j<=W;j++)
            {
                if(j>=S) sum -= m[j-S][i]-m[j-S][i-T];
                sum += m[j][i]-m[j][i-T];
                if(sum>maxx) maxx = sum;
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}
