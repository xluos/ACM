#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    vector<int>ve;
    int f,flag;
}mp[5070];
int main()
{
    int n,m,ans;
    char ch[10];
    //map<int,node>mp;
    cin>>n;
    mp[0].f=5061;
    mp[5061].f=5066;
    mp[5061].flag=1;
    for(int i=1;i<n;i++)
    {
        int ans;
        scanf("%d",&ans);
        mp[ans].ve.push_back(i);
        mp[i].f=ans;
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        scanf("%s %d",ch,&ans);
        if(ch[0]=='S')
        {
            int sum=0;
            while(mp[ans].f!=5066)
            {
                if(mp[ans].flag!=1)
                {
                    sum++;
                    mp[ans].flag=1;
                }
                ans=mp[ans].f;
            }
            printf("%d\n",sum);
        }
        else
        {
            int sum=0;
            queue<int>q;
            q.push(ans);
            while(!q.empty())
            {
                int p=q.front();
                q.pop();
                int l=mp[p].ve.size();
                if(mp[p].flag==1)
                {
                    mp[p].flag=0;
                    sum++;
                    cout<<p<<"*"<<endl;
                }
                else
                    break;
                for(int i=0;i<l;i++)
                {
                    int ans=mp[p].ve[i];
                    if(mp[ans].flag!=1)
                        continue;
                    q.push(ans);
                }
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
