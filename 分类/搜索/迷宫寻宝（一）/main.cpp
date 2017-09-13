#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
int a,b,c,d,e;
char cha[]={'A','B','C','D','E'};
int m,n,bj;
struct zuobiao{
    int x,y;
    int sum;
}p,k;
char t[30][30];
int vis[30][30]={0};
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
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
/**
测试数据
5 5
e.b.S
XXA.E
GX.Xc
C...X
XXXBX
5 5
e.b.S
XXA.E
GX.Xc
C....
XXXBX
5 5
ecb.S
XaX.E
GX.Xc
CA...
XXXcX
5 5
Xae.S
cXX.E
XXXXc
CAA..
GXXcX
5 5
AEe.S
cXX.E
XXXXc
CAA..
GXXcX
5 5
Aae.S
cXX.E
XXXXc
CAAE.
GXXcX
1 2
SG
1 3
SXG
5 5
SXaXG
.X.X.
.X.X.
.X.XA
.....
5 5
aE..S
bXX.c
XX.CX
GBA.B
XXe.e
5 5
a...a
XX.XX
bXSXG
.XAXB
.....
5 5
.X.XG
Sa..A
.b.Xc
XX..B
bC...
5 5
.X.XG
Sb..B
.b.Xc
XX..B
bC...
1 10
S.aAbBcC.G
0 0

*/
