#include <bits/stdc++.h>

using namespace std;
struct node{
    int time,price;
    friend bool operator < (node a, node b)
    {
        if(a.price == b.price)
            return a.time<b.time;
        return a.price > b.price;    //结构体中，x小的优先级高
    }
};
queue<node>q;
priority_queue<node>pq;
map<node,int>mp;
int main()
{
    int n;
    cin>>n;
    getchar();
    for(int i=0;i<n;i++)
    {
        char ch;
        node no;
        int ans;
        scanf("%c",&ch);
        getchar();
        switch(ch)
        {
        case 'P':
            scanf("%d%d",&no.time,&no.price);
            getchar();
            q.push(no);
            mp[no]=1;
            break;
        case 'R':
            scanf("%d",&ans);
            getchar();
            while(q.front().time<=ans)
            {
                mp[q.front()]=0;
                q.pop();
            }
            break;
        case 'Q':
            for(map<node,int>::iterator it=mp.begin();it!=mp.end();it++)
            {
                if(it->second==1)
                {
                    printf("%d ",(it->first).price);
                    break;
                }
            }
            for(map<node,int>::reverse_iterator it=mp.rbegin();it!=mp.rend();it++)
            {
                if(it->second==1)
                {
                    printf("%d ",(it->first).price);
                    break;
                }
            }
            printf("%d\n",q.back().price);
            break;
        }
    }
    return 0;
}
