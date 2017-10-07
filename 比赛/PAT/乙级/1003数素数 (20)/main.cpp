#include <bits/stdc++.h>

using namespace std;
int a[104799]={0},su[10005];
void init()
{
    int k=0;
    a[0]=a[1]=1;
    for(int i=2;i<104799&&k<10005;i++)
    {
        if(!a[i])
        {
            su[k]=i;
            k++;
            for(int j=i+i;j<104799;j+=i)
            {
                a[j]=1;
            }
        }
    }
}

int main()
{
    init();
    int n,m;
    cin>>n>>m;
    for(int i=n;i<=m;i++)
    {
        if((i-n+1)%10==0||i==m)
            printf("%d\n",su[i-1]);
        else
            printf("%d ",su[i-1]);
    }
    return 0;
}
