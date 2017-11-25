#include <bits/stdc++.h>
#define N 210
#define K 200
using namespace std;
int a[N],b[K];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,k,flag=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<k;i++)
        scanf("%d",&b[i]);
    sort(b,b+k,cmp);
    for(int i=0,j=0;i<n;i++)
    {
        if(!a[i])
            a[i]=b[j++];
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]<=a[i-1])
        {
            flag=1;
            break;
        }
    }
    if(flag)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
