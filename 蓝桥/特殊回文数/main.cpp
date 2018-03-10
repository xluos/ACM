#include <bits/stdc++.h>

using namespace std;
int sum5(int a, int b, int c)
{
    return a+a+b+b+c;
}
int sum6(int a, int b, int c)
{
    return a+a+b+b+c+c;
}
int main()
{
    int n,arr5[1000],arr6[1000],len5=0,len6=0;
    scanf("%d",&n);
    for(int i=1;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                if(n==sum5(i,j,k))
                {
                    arr5[len5++] = i*10000 + j*1000 +k*100 +j*10+i;
                }
                if(n==sum6(i,j,k))
                {
                    arr6[len6++] = i*100000 + j*10000 +k*1100 +j*10+i;
                }
            }
        }
    }
    for(int i=0;i<len5;i++)
    {
        printf("%d\n",arr5[i]);
    }
    for(int i=0;i<len6;i++)
    {
        printf("%d\n",arr6[i]);
    }
    return 0;
}
