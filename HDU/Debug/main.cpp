#include <bits/stdc++.h>

using namespace std;
struct node{
    int data;
    int step;
};
const int N = 200005;
int n,m,vis[N];
int bfs()
{
    node p,q;
    p.data = n;
    p.step = 0;
    queue<node>Q;
    Q.push(p);
    while(!Q.empty())
    {
        p = Q.front();
        Q.pop();
        if(p.data == m) return p.step;
        for(int i=0;i<3;i++)
        {
            switch(i)
            {
                case 0: q.data = p.data - 1; break;
                case 1: q.data = p.data + 1; break;
                case 2: q.data = p.data * 2; break;
            }
            q.step = p.step + 1;
            if(q.data >= 0 && q.data < N && !vis[q.data])
            {
                vis[q.data] = 1;
                //printf("data == %d step == %d m==%d  \n",q.data,q.step,m);
                Q.push(q);
                if(q.data == m) return q.step;
            }
        }
    }
}
int main()
{

    while(~scanf("%d %d",&n,&m))
    {
        if(n>m)
        {
            cout<<n-m<<endl;
        }
        else
        {
            memset(vis,0,sizeof(vis));
            cout<<bfs()<<endl;
        }

    }
    return 0;
}
