#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k,ren[30]={0};
    while(~scanf("%d %d %d",&n,&k,&m),k+m+n)
    {
        int count_k=0,count_m=0,flag=n,i=1,j=n;
        for(int i=1;i<=n;i++) ren[i]=i;
        while(n)
        {
            for(count_k=0;;i++)
            {
                if(i>flag) i%=flag;
                if(ren[i]) count_k++;
                if(count_k==k) break;
            }
            for(count_m=0;;j--)
            {
                if(j<0) j=flag;
                if(ren[j]) count_m++;
                if(count_m==m) break;
            }
            if(i==j)
            {
                printf("%3d",ren[i]);
                n--;
            }
            else
            {
                printf("%3d%3d",ren[i],ren[j]);
                n-=2;
            }
            ren[i]=0;ren[j]=0;
            if(n) printf(",");
        }
        cout<<endl;
    }
    return 0;
}
