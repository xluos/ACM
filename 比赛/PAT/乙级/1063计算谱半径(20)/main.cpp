#include <bits/stdc++.h>

using namespace std;
double p(int a,int b)
{
    return sqrt(a*a+b*b);
}
int main()
{
    int n,a,b;
    double maxx=0;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        maxx=max(p(a,b),maxx);
    }
    printf("%.2lf\n",maxx);
    return 0;
}
