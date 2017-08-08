#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k,ren[30]={0};
    while(~scanf("%d %d %d",&n,&k,&m),k+m+n)
    {
        int count_k=0,count_m=0,flag=0;
        for(int i=1;i<=n;i++) ren[i]=i;
        for(int i=1;;i++)
        {
            if(i>n)i%=n;
            if(ren[i])
            {
                count_k++;
                count_m++;
            }
            if(count_k==k)
            {
                count_k=0;
                printf("%3d",ren[i]);
                ren[i]=0;
                n--;
                flag++;
            }
            if(count_m==m)
            {
                count_m=0;
                if(ren[i])
                {
                    printf("%3d",ren[i]);
                    ren[i]=0;
                    n--;
                    flag++;
                }
            }
            if(flag&&n) {flag=0;printf(",");}
        }
    }
    return 0;
}
