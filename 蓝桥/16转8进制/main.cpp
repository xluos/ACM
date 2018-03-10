#include <bits/stdc++.h>

using namespace std;
char h[100004],o[150000],b[400005];
int geto(int k)
{
    int sum=0,a[]={1,2,4};
    for(int i=k;i<k+3;i++)
    {
        sum = sum+b[i]*a[i-k];
    }
    return sum;
}
int gethex(char c)
{
    if(c<'A') return c-'0';
    return c-'A'+10;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        memset(h,0,sizeof(h));
        memset(o,0,sizeof(o));
        memset(b,0,sizeof(b));
        scanf("%s",h);
        int len16 = strlen(h),num,lenb=0;
        for(int i=len16-1;i>=0;i--)
        {
            num = gethex(h[i]);
            for(int j=0;j<4;j++)
            {
                b[lenb++] = num%2;
                num /= 2;
            }
        }
        int i=0;
        for(int k=0;k<lenb;k+=3,i++)
        {
            o[i] = geto(k);
        }
        while(!o[i]) i--;
        for(;i>=0;i--)
        {
            printf("%d",o[i]);
        }
        printf("\n");
    }
    return 0;
}
