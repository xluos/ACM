#include <iostream>
#include <cstdio>

using namespace std;

int g(int a,int b)
{
    return (b==0)?a:g(b,a%b);
}
int main()
{
    int w;
    scanf("%d",&w);
    while(w--)
    {
        int n,m;
        double sum=1,ans;
        scanf("%d %d",&m,&n);
        if(m>n/2)
            m=n-m;
        for(int i=n,k=m; i>n-m; i--,k--)
        {
            sum*=i;
            sum/=k;
            if(sum>=1007)
            {
                ans=sum-(int)sum;
                sum=(int)sum%1007;
                sum+=ans;
                if(sum==0)sum=1;
            }
        }
        cout<<(int)sum<<endl;
    }
    return 0;
}
