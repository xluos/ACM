#include <bits/stdc++.h>
//#include <windows.h>
using namespace std;
const int N  = 22;
int dir[][2] = {0,1,1,0,0,-1,-1,0};
char Chart[N][N];
int vis[N][N],qx,qy;
int X,Y,n,m;
struct node{
    int x,y,step;
    friend bool operator < (node a,node b)
    {
        return a.step > b.step;
    }
};
bool judge(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m||Chart[x][y] == '*'||vis[x][y]>4)
        return false;
    return true;
}
void out()
{
    //system("cls");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(Chart[i][j] == '*') printf("* ");
            else printf("%d ",vis[i][j]);
        }
        printf("\n");
    }
}
int BFS(int x,int y)
{
    node q,p;
    priority_queue<node>Q;
    q.x = x;
    q.y = y;
    q.step = 0;
    Q.push(q);
    vis[x][y] = 5;
    while(!Q.empty())
    {
        q = Q.top();
        Q.pop();
        //out();
        if(q.x == X && q.y == Y)
        {
            return q.step;
        }
        //cout<<q.x<<' '<<q.y<<' '<<q.step<<' '<<Chart[q.x][q.y]<<endl;
        for(int i=0;i<4;i++)
        {
            p.x = q.x + dir[i][0];
            p.y = q.y + dir[i][1];
            p.step = q.step + 1;
            if(p.x == X && p.y == Y)
            {
                return p.step;
            }
            if(judge(p.x,p.y))
            {
                if(Chart[p.x][p.y] == '.')
                {
                    vis[p.x][p.y] = 5;
                    Q.push(p);
                    //cout<<p.x<<' '<<p.y<<' '<<p.step<<' '<<Chart[p.x][p.y]<<endl;
                }
                else if(judge(p.x + dir[i][0],p.y + dir[i][1]))
                {
                    node ans;
                    ans.x = p.x + dir[i][0];
                    ans.y = p.y + dir[i][1];
                    ans.step = p.step;
                    vis[ans.x][ans.y] = 5;
//                    if(!((Chart[p.x][p.y] == '|' && i&1 == q.step&1)||(Chart[p.x][p.y] == '-' && i&1 != q.step&1)))
//                        ans.step++;
                    if(q.step&1)
                    {
                        if(i&1)
                        {
                            if(Chart[p.x][p.y] == '|')
                                ans.step++;
                        }
                        else
                        {
                            if(Chart[p.x][p.y] == '-')
                                ans.step++;
                        }
                    }
                    else
                    {
                        if(i&1)
                        {
                            if(Chart[p.x][p.y] == '-')
                                ans.step++;
                        }
                        else
                        {
                            if(Chart[p.x][p.y] == '|')
                                ans.step++;
                        }
                    }
                    Q.push(ans);
                    if(ans.x == X && ans.y == Y)
                    {
                        return ans.step;
                    }
                    //cout<<ans.x<<' '<<ans.y<<' '<<ans.step<<' '<<Chart[ans.x][ans.y]<<endl;
                }
            }
        }
    }
    return -1;
}
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        memset(Chart,0,sizeof(Chart));
        memset(vis,0,sizeof(vis));
        for(int i = 0;i<n;i++)
        {
            getchar();
            for(int j = 0;j<m;j++)
            {
               scanf("%c",&Chart[i][j]);
               if(Chart[i][j] == 'S')
               {
                   Chart[i][j] = '.';
                   qx = i; qy = j;
               }
               else if(Chart[i][j] == 'T')
               {
                   Chart[i][j] = '.';
                   X = i; Y = j;
               }

            }
        }
        //cout<<X<<' '<<Y<<endl;
        cout<<BFS(qx,qy)<<endl;
    }
    return 0;
}
/*
5 5
**..T
**.*.
..|..
.*.*.
S....

3 4
S|.|
-T-.
.|..

20 20
S.|.|.|.|.|.|.|.|.|.
.|.|.|.|.|.|.|.|.|.|
|.|.|.|.|.|.|.|.|.|.
.|.|.|.|.|.|.|.|.|.|
|.|.|.|.|.|.|.|.|.|.
.|.|.|.|.|.|.|.|.|.|
|.|.|.|.|.|.|.|.|.|.
.|.|.|.|.|.|.|.|.|.|
|.|.|.|.|.|.|.|.|.|.
.|.|.|.|.|.|.|.|.|.|
|.|.|.|.|.|.|.|.|.|.
.|.|.|.|.|.|.|.|.|.|
|.|.|.|.|.|.|.|.|.|.
.|.|.|.|.|.|.|.|.|.|
|.|.|.|.|.|.|.|.|.|.
.|.|.|.|.|.|.|.|.|.|
|.|.|.|.|.|.|.|.|.|.
.|.|.|.|.|.|.|.|.|.|
|.|.|.|.|.|.|.|.|.|.
.|.|.|.|.|.|.|.|.|.T


3 4
T...
*-*S
*.|.

*/
