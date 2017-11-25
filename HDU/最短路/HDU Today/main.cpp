#include <bits/stdc++.h>

using namespace std;
const int MAX = 6;
int num[10],sum=0;
void s(int n)
{
    if(n >= MAX)
    {
        for(int i=0;i<MAX;i++)
        {
            printf("%d ",num[i]);
        }
        sum++;
        printf("\n");
    }
    for(int i=1;i<=6;i++)
    {
        num[n] = i;
        s(n+1);
    }
}
int main()
{
    s(0);
    cout<<sum<<endl;
    return 0;
}
