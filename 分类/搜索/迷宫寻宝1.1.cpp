#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int x,y;
};
int m,n,A,B,C,D,E,sx,sy,ex,ey;
char Map[25][25];
int vis[25][25],dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int bfs()
{
    queue<Node> Q;
    Node cur,next;
    cur.x=sx;cur.y=sy;
    memset(vis,0,sizeof(vis));
    vis[cur.x][cur.y]=1;
    Q.push(cur);
    while(!Q.empty())
    {
    	//cout<<'a';
        cur=Q.front();
        Q.pop();
        cout<<cur.x<<' '<<cur.y<<' '<<Map[cur.x][cur.y]<<endl;
		if(cur.x==ex&&cur.y==ey)
        {
        	cout<<cur.x<<' '<<cur.y<<' '<<Map[cur.x][cur.y]<<endl;
        	cout<<ex<<ey<<endl;
        	cout<<"bbbbbbbbbbbbbbbb";
            return 1;
        }
        for(int i=0;i<4;i++)
        {
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];
            if(next.x>=0&&next.x<m&&next.y>=0&&next.y<n&&vis[next.x][next.y]==0&&Map[next.x][next.y]!='X')
            {
                if(Map[next.x][next.y]=='.')  vis[next.x][next.y]=1,Q.push(next);
                //else if(Map[next.x][next.y]=='G')return 1;
                else if(Map[next.x][next.y]=='a'){
                    A--;
                    Map[next.x][next.y]='.';
                    vis[next.x][next.y]=1;
                    Q.push(next);
                }
                else if(Map[next.x][next.y]=='b'){
                    B--;
                    Map[next.x][next.y]='.';
                    vis[next.x][next.y]=1;
                    Q.push(next);
                }
                else if(Map[next.x][next.y]=='c'){
                    C--;
                    Map[next.x][next.y]='.';
                    vis[next.x][next.y]=1;
                    Q.push(next);
                }
                else if(Map[next.x][next.y]=='d'){
                    D--;
                    Map[next.x][next.y]='.';
                    vis[next.x][next.y]=1;
                    Q.push(next);
                }
                else if(Map[next.x][next.y]=='e'){
                    E--;
                    Map[next.x][next.y]='.';
                    vis[next.x][next.y]=1;
                    Q.push(next);
                }
                else if(Map[next.x][next.y]=='A'){
                    if(A==0){
                    Map[next.x][next.y]='.';
                    vis[next.x][next.y]=1;
                    Q.push(next);}
                }
                else if(Map[next.x][next.y]=='B'){
                    if(B==0){
                    Map[next.x][next.y]='.';
                    vis[next.x][next.y]=1;
                    Q.push(next);}
                }
                else if(Map[next.x][next.y]=='C'){
                    if(C==0){
                    Map[next.x][next.y]='.';
                    vis[next.x][next.y]=1;
                    Q.push(next);}
                }
                else if(Map[next.x][next.y]=='D'){
                    if(D==0){
                    Map[next.x][next.y]='.';
                    vis[next.x][next.y]=1;
                    Q.push(next);}
                }
                else if(Map[next.x][next.y]=='E'){
                    if(E==0){
                    Map[next.x][next.y]='.';
                    vis[next.x][next.y]=1;
                    Q.push(next);}
                }
            }

        }

    }
    return 0;
}
int used[10];
int main()
{
    while(cin>>m>>n,m+n)
    {
        A=B=C=D=E=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                cin>>Map[i][j];
                if(Map[i][j]=='S')
                    sx=i,sy=j,Map[i][j]='.';
                else if(Map[i][j]=='G')
                    ex=i,ey=j;
                else if(Map[i][j]=='a')A++;
                else if(Map[i][j]=='b')B++;
                else if(Map[i][j]=='c')C++;
                else if(Map[i][j]=='d')D++;
                else if(Map[i][j]=='e')E++;
            }
		for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                cout<<Map[i][j];
            }
        int ans;
        memset(used,0,sizeof(used));
        if(A==0)used[1]=1;
        if(B==0)used[2]=1;
        if(C==0)used[3]=1;
        if(D==0)used[4]=1;
        if(E==0)used[5]=1;
        if(bfs())
            cout<<"YES"<<endl;
        else
        {
           /* while(1)
            {
                if(A==0&&used[1]==0)
                {

                    ans=bfs();used[1]=1;
                    if(ans)
                    break;
                }
                else if(B==0&&used[2]==0)
                {
                    ans=bfs();used[2]=1;
                    if(ans)
                    break;
                }
                else if(C==0&&used[3]==0)
                {
                    ans=bfs();used[3]=1;
                    if(ans)
                    break;
                }
                else if(D==0&&used[4]==0)
                {
                    ans=bfs();used[4]=1;
                    if(ans)
                    break;
                }
                else if(E==0&&used[5]==0)
                {
                    ans=bfs(); used[5]=1;
                    if(ans)
                    break;
                }
            }
            if(ans)cout<<"YES"<<endl;
            else  */cout<<"NO"<<endl;
        }
        		for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                cout<<Map[i][j];
            }
    }
    return 0;
}

