#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    int t[2*100001];
    cin>>w;
    while(w--)
    {
        int n,m,ans,k,maxx=0,flag=1;
        vector<int>ve;
        memset(t,0,sizeof(t));
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&k);
            t[k]=1;
            if(k>maxx) maxx=k;
        }
        for(int i=1; i<=maxx+1; i++)
        {
            if(t[i]==0)
            {
                ve.push_back(i);
            }
        }
//        for(int i=0; i<ve.size(); i++)
//        {
//            cout<<ve[i];
//        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&k);
            if(k>maxx) printf("%d\n",k);
            else{
                ans = lower_bound(ve.begin(),ve.end(),k)-ve.begin();
                printf("%d\n",ve[ans]);
            }

        }
    }
    return 0;
}












