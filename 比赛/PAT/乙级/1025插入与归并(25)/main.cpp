#include <bits/stdc++.h>

using namespace std;
int yuanshi[105],mubiao[105],n,ans[105],flag=0;
int juedg(int a[],int b[],int l)
{
    for(int i=0;i<l;i++)
    {
        if(a[i]!=b[i])
            return 0;
    }
    return 1;
}
void mergepass(int a[],int b[],int k,int n)
{
    if(juedg(mubiao,a,n))
    {
        printf("Merge Sort\n");
        flag=1;
    }
    if(flag==2)return ;
    int i;
    for(i=0;i<=n-k*2;i+=k*2)
    {
        merge(a+i,a+i+k,a+i+k,a+i+2*k,b+i);
    }
    if(n<k*2)
        merge(a,a+k,a+k,a+n,b);
    if(flag)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d%c",b[i],i==n-1?'\n':' ');
        }
        flag=2;
        return ;
    }

}
void input()
{
    for(int i=0;i<n;i++)
        scanf("%d",&yuanshi[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&mubiao[i]);
}
int main()
{

    cin>>n;
    input();
    copy(yuanshi,yuanshi+n,ans);
    for(int i=1;i<n;i++)
    {
        if(ans[i]<ans[i-1])
        {
            if(juedg(mubiao,ans,n))
            {
                printf("Insertion Sort\n");
                flag=1;
            }
            int p=upper_bound(ans,ans+i,ans[i])-ans,q=ans[i];
            copy(ans+p,ans+i,ans+p+1);
            ans[p]=q;
            if(flag)
            {
                for(int i=0;i<n;i++)
                {
                    printf("%d%c",ans[i],i==n-1?'\n':' ');
                }
                return 0;
            }

        }else if(!flag&&i==n-1)
        {
             printf("Insertion Sort\n");
             for(int i=0;i<n-1;i++)
                printf("%d ",ans[i]);
             printf("%d\n",ans[n-1]);
             flag=1;
        }
    }
    if(!flag)
    {
    int k=1;
    while(k<n)
    {

        mergepass(yuanshi,ans,k,n);
        k<<=1;
        mergepass(ans,yuanshi,k,n);
        k<<=1;
        if(flag==2)
            break;
    }}
    return 0;
}
