#include <bits/stdc++.h>

using namespace std;

int main()
{
    int mp[105]={0},ans;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ans);
        mp[ans]++;
    }
    cin>>n;
    while(n--)
    {
        scanf("%d",&ans);
        printf("%d%c",mp[ans],n?' ':'\n');
    }
    return 0;
}
