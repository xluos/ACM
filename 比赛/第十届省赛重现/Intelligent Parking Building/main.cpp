#include <iostream>
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct Node{
    int num,id;
} ;
bool cmp(Node a,Node b)
{
    return a.num<b.num;
}
int abs(int n)
{
    return n<0?-n:n;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n,m,sum=0;
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;i++)
        {
            int Count = 0,ans;
            Node a[55];
            for(int j=0;j<n;j++)
            {
                scanf("%d",&ans);
                if(ans!=-1)
                {
                    a[Count].num=ans;
                    a[Count].id = j;
                    Count++;
                }
            }
            sort(a,a+Count,cmp);
            sum+=20*Count*i;
            if(Count)
                sum+=5*min(a[0].id,abs(n-a[0].id));
            for(int j=1;j<Count;j++)
            {
                sum+=5*min(abs(a[j].id-a[j-1].id),abs(n+min(a[j].id,a[j-1].id)-max(a[j].id,a[j-1].id)));
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
