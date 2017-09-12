#include <bits/stdc++.h>

using namespace std;
pair<int,int> a[6];
int cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}
int main()
{
    int flag=1;
    while(~scanf("%d %d",&a[0].first,&a[0].second))
    {
        for(int i=1;i<6;i++)
            scanf("%d %d",&a[i].first,&a[i].second);
        for(int i=0;i<6;i++)
        {
            if(a[i].first>a[i].second)
            {
                int t=a[i].first;
                a[i].first=a[i].second;
                a[i].second=t;
            }
        }
        sort(a,a+6,cmp);
        if(a[0].first==a[1].first&&a[0].second==a[1].second&&
           a[2].first==a[3].first&&a[2].second==a[3].second&&
           a[4].first==a[5].first&&a[4].second==a[5].second&&
           a[0].first==a[2].first&&a[0].second==a[4].first&&
           a[2].second==a[4].second)
            printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }

    return 0;
}
