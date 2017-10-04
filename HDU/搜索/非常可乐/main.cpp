#include <bits/stdc++.h>

using namespace std;
int s[3];
int dir[][2] = {0,1,0,2,1,0,1,2,2,0,2,1};
struct node{
    int n[3],step;
    friend bool operator < (node a,node b)
    {
        if(a.n[0] == b.n[0])
        {
            if(a.n[1] == b.n[1])
            {
                return a.n[2]<b.n[2];
            }
            return a.n[1]<b.n[1];
        }
        return a.n[0]<b.n[0];
    }
};
bool judge(node p)
{
    if((p.n[0] == p.n[1]&&p.n[2] == 0)||
       (p.n[0] == p.n[2]&&p.n[1] == 0)||(p.n[2] == p.n[1]&&p.n[0] == 0))
        return true;
    return false;
}
node swap(node q,int a,int b)
{
    if(q.n[a] > s[b]-q.n[b])
    {
        q.n[a] -= (s[b]-q.n[b]);
        q.n[b] = s[b];
    }
    else
    {
        q.n[b] += q.n[a];
        q.n[a] = 0;
    }
    q.step++;
    return q;
}
void BFS(int x,int y,int z)
{
    node q,p;
    queue<node>Q;
    map<node,int>mp;
    q.n[0] = x; q.n[1] = y;q.n[2] = z;
    q.step = 0;
    Q.push(q);
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        for(int i=0;i<6;i++)
        {
            p = swap(q,dir[i][0],dir[i][1]);
            if(judge(p))
            {
                printf("%d\n",p.step);
                return ;
            }
            else
            {
                if(!mp[p])
                {
                    mp[p] = 1;
                    Q.push(p);
                }
            }
        }
    }
    printf("NO\n");
    return ;
}
int main()
{
    while(scanf("%d %d %d",&s[0],&s[1],&s[2]),s[0]+s[1]+s[2])
    {
        BFS(s[0],0,0);
    }
    return 0;
}
