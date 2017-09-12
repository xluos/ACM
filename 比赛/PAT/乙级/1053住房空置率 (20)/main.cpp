#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,d,k=0,t=0;
    double e,ans;
    cin>>n>>e>>d;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        int sum=0;
        for(int j=0;j<m;j++)
        {
            cin>>ans;
            if(ans<e) sum++;
        }
        if(sum>m/2) m>d?t++:k++;
    }
    printf("%.1lf%% %.1lf%%\n",k*100.0/n,t*100.0/n);
    return 0;
}
