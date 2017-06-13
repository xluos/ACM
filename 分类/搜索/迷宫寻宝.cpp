#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
char cha[]={'A','B','C','D','E'};
char t[30][30];
int a,b,c,d,e;
int m,n,bj;
int vis[30][30]={0};
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
struct zuobiao{
    int x,y;
    int sum;
}p,k;

queue<zuobiao>q;
int gai()
{
    if(a==0)
    {a=-1;return 0;}
    if(b==0)
    {b=-1;return 1;}
    if(c==0)
    {c=-1;return 2;}
    if(d==0)
    {d=-1;return 3;}
    if(e==0)
    {e=-1;return 4;}
    return -1;
}
int pan(char ch)
{
    if(t[k.x][k.y]=='.'
       ||t[k.x][k.y]=='a'
       ||t[k.x][k.y]=='b'||t[k.x][k.y]=='c'
       ||t[k.x][k.y]=='d'||t[k.x][k.y]=='e'
       ||t[k.x][k.y]=='G')
        return 1;
    return 0;
}
int key_jian(char ch)
{
    if(ch=='a')a--;
    else if(ch=='b')b--;
    else if(ch=='c')c--;
    else if(ch=='d')d--;
    else if(ch=='e')e--;
    else return 0;
    return 1;
}
void key(char ch)
{
    if(ch=='a')a++;
    else if(ch=='b')b++;
    else if(ch=='c')c++;
    else if(ch=='d')d++;
    else if(ch=='e')e++;
}
void bfs(int q_x,int q_y,int z_x,int z_y)
{
    memset(vis,0,sizeof(vis));
    while(!q.empty())q.pop();
    p.x=q_x;
    p.y=q_y;
    p.sum=0;
    q.push(p);
    vis[p.x][p.y]=1;
    while(!q.empty())
    {

        p=q.front();
        q.pop();
//        cout<<t[p.x][p.y]<<endl;
//        cout<<p.x<<'.'<<p.y<<endl;
//        cout<<z_x<<'.'<<z_y<<endl;
        if(p.x==z_x&&p.y==z_y)
        {
            cout<<"YES"<<endl;
            t[z_x][z_y]='X';
            bj=0;
            return ;
        }
        for(int i=0;i<4;i++)
        {
            k.x=p.x+dir[i][0];
            k.y=p.y+dir[i][1];
            if(k.x>=0&&k.x<m&&k.y>=0&&k.y<n&&
               (pan(t[k.x][k.y]))&&vis[k.x][k.y]==0)
            {
                if(key_jian(t[k.x][k.y]))
                    t[k.x][k.y]='.';
                vis[k.x][k.y]=1;
                q.push(k);
            }
        }
    }
    int linshi=gai();
    if(linshi>=0)
    {
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
        {
            if(t[i][j]==cha[linshi])
            {
                t[i][j]='.';
            }
        }
        cout<<endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
        {
            cout<<t[i][j];
        }
        cout<<endl;
        }
    }

}
int main()
{
    int q_x,q_y,z_x,z_y,w;

    while(cin>>m>>n,m+n)
    {
        bj=1;
        a=b=c=d=e=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
        {
            cin>>t[i][j];
            if(t[i][j]=='S')
            {
                q_x=i;q_y=j;
            }
            if(t[i][j]=='G')
            {
                z_x=i;z_y=j;
            }
            key(t[i][j]);
        }
        for(int i=0;i<6&&bj==1;i++)
        {
            bfs(q_x,q_y,z_x,z_y);
        }
        
        if(bj)
        cout<<"NO"<<endl;
    }
    return 0;
}

/*#include <iostream>
#include <string.h>
#include <queue>
#include <cstdio>
#include <string.h>
using namespace std;
struct node{
int x, y;
};
char mp[25][25], c;
int n, m;
int need[25], have[25];
int x1, y1, x2, y2;

int const mx[4] = {0, 0, 1, -1};
int const my[4] = {1, -1, 0, 0};

int bfs()
{
int vis[25][25];
memset(vis, 0, sizeof(vis));
int flag = 0;//判断手中的钥匙有没有变化
queue<node> q;
node u;
u.x = x1, u.y = y1;
vis[x1][y1] = 1;
q.push(u);
while(!q.empty()){
u = q.front();
if(u.x == x2 && u.y == y2) return 1;//返回1说明已经找到宝藏了
q.pop();
for(int i = 0; i < 4; i++){
int x = u.x + mx[i];
int y = u.y + my[i];
char &p = mp[x][y];
if(x > n || x <= 0 || y > m || y <= 0) continue;
if(vis[x][y]) continue;
if(p == 'X') continue;
if(p >= 'a' && p <= 'e') {have[p-'a']++; p = '.'; flag = 1;}
if(p >= 'A' && p <= 'E')
if(have[p-'A'] < need[p-'A'])
continue;
node v;
v.x = x, v.y = y;
vis[x][y] = 1;
q.push(v);
}
}
if(!flag) return -1;//返回-1说明手里的钥匙没有增加，这次找不到，以后也就没有找到宝藏的希望了
else return 0;//返回0说明手里的钥匙增加了，或许下一次bfs就能找到宝藏
}

int main()
{
while(cin >> n >> m && n && m){
getchar();
memset(have, 0, sizeof(have));
memset(need, 0, sizeof(need));
for(int i = 1; i <= n; i++){
for(int j = 1; j <= m; j++){
cin >> c;
mp[i][j] = c;
if(c >= 'a' && c <= 'e') need[c-'a']++;
if(c=='S') {x1 = i, y1 = j;}
if(c=='G') {x2 = i, y2 = j;}
}
getchar();
}
while(1){
int t = bfs();
if(t == 1) {cout << "YES" << endl; break;}
if(t == 0)
continue;
if(t == -1) {cout << "NO" << endl; break;}
}
}
return 0;
}*/
