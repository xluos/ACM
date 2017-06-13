#include <iostream>
#include <cstdio>
#define min(a,b) (a>b?b:a)

using namespace std;

int main()
{
    int w;cin>>w;
    while(w--)
    {
        int n,num=0,num_f=0,k=1,key=0;
        double sum=0,being,end,ans[100005],max=-0x3f3f3f3f,min=-0x3f3f3f3f;
        cin>>n;
        for(int i=0;i<n;i++)
            scanf("%lf",&ans[i]);
        for(int i=0;i<n;i++)
        {

            if(k)
            {
                being=i;
                k=0;
            }
            if(ans[i]<0)
            {
                if(ans[i]>min)
                    min=ans[i];
                num_f++;
            }
            sum+=ans[i];
            num++;
            if(sum==0)
            {
                key|=num&1;
            }
            if(sum<=0)
            {
                k=1;
                num=0;
                sum=0;
            }
            if(sum>max)
            {
                end=i;
                max=sum;
            }
        }
        if(num_f==n)
            cout<<min<<endl;
        else
        {
            if(!(num&1)&&being!=end&&!(key&1))
                max-=min(ans[(int)being],ans[(int)end]);
            cout<<max<<endl;
        }
    }
    return 0;
}
