#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,t=1;
    while(scanf("%d",&n),n)
    {
        map<int ,int>mp,weizhi;
        int ans,ok=0,cz=0,sum;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&ans);
            mp[ans]++;
            weizhi[i]=ans;
        }
        printf("Game %d:\n",t++);
        while(1)
        {
            sum=ok=cz=0;
            map<int,int>flag,num;
            for(int i=1;i<=n;i++)
            {
                scanf("%d",&ans);
                sum+=ans;
                if(weizhi[i]==ans) ok++;
                num[ans]++;
            }
            for(int i=0;i<=9;i++)
                cz+=min(num[i],mp[i]);
            if(!sum) break;
            else printf("    (%d,%d)\n",ok,cz-ok);
        }
    }
    return 0;
}
