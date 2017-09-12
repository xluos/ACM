#include <bits/stdc++.h>

using namespace std;
struct node{
    char ID;
    int x,y;
};
int dir[][2]={-1,2,1,2,-2,1,-2,-1,-1,-2,1,-2,2,1,2,-1};
int dir2[][2]={0,1,0,1,-1,0,-1,0,0,-1,0,-1,1,0,1,0};
int qipan[11][10];
void GRlu(node qizi)
{
    int x=qizi.x,y=qizi.y;
    for(int i=x+1;i<11;i++)
        if(qipan[i][y]==0) qipan[i][y]=1;
        else
        {
            if(qipan[i][y]==-1) qipan[i][y]=1;
            break;
        }
    for(int i=x-1;i>0;i--)
        if(qipan[i][y]==0) qipan[i][y]=1;
        else
        {
            if(qipan[i][y]==-1) qipan[i][y]=-2;
            break;
        }
    for(int i=y+1;i<10;i++)
        if(qipan[x][i]==0) qipan[x][i]=1;
        else
        {
            if(qipan[x][i]==-1) qipan[x][i]=-2;
            break;
        }
    for(int i=y-1;i>0;i--)
        if(qipan[x][i]==0) qipan[x][i]=1;
        else
        {
            if(qipan[x][i]==-1) qipan[x][i]=-2;
            break;
        }
}
void putqipan()
{
    for(int i=0;i<11;i++)
    {
        for(int j=1;j<10;j++)
        {
            cout<<qipan[i][j]<<"  ";
        }
        cout<<endl;
    }
}
void Hlu(node qizi)
{
    int x=qizi.x,y=qizi.y,X,Y,xx,yy;
    for(int i=0;i<8;i++)
    {
        X=x+dir[i][0];
        Y=y+dir[i][1];
        xx=x+dir2[i][0];
        yy=y+dir2[i][1];
        if(xx>0&&xx<11&&X>0&&X<11&&yy>0&&yy<10&&Y>0&&Y<10&&qipan[xx][yy]>=0)
            qipan[X][Y]=1;
    }
}
void Clu(node qizi)
{
    int x=qizi.x,y=qizi.y;
    for(int i=x+1;i<11;i++)
    {
        if(qipan[i][y]<0)
        {
            for(i++;i<11&&qipan[i][y]>=0;i++)
                qipan[i][y]=1;
            if(i<11) qipan[i][y]=-2;
        }
    }
    for(int i=x-1;i>0;i--)
    {
        if(qipan[i][y]<0)
        {
            for(i--;i>0&&qipan[i][y]>=0;i--)
                qipan[i][y]=1;
            if(i>0) qipan[i][y]=-2;
        }
    }
    for(int i=y+1;i<10;i++)
    {
        if(qipan[x][i]<0)
        {
            for(i++;i<10&&qipan[x][i]>=0;i++)
                qipan[x][i]=1;
            if(i<10) qipan[x][i]=2;
        }
    }
    for(int i=y-1;i>0;i--)
    {
        if(qipan[x][i]<0)
        {
            for(i--;i>0&&qipan[x][i]>=0;i--)
                qipan[x][i]=1;
            if(i>0) qipan[x][i]=-2;
        }
    }
}
int judeg(int x,int y)
{
    int k=4;
    int dir[][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,-1,-1,1};
//    if(((x==1||x==3)&&(y==4||y==6))||(x==2&&x==5)) k=8;
//    else k=4;
    for(int i=0;i<k;i++)
    {
        int X=x+dir[i][0],Y=y+dir[i][1];
        //cout<<X<<Y<<endl;
        if(Y>3&&Y<7&&X>0&&X<4)
        {

            if(qipan[X][Y]==0||qipan[X][Y]==-1)
                return 0;
            //qipan[X][Y]=8;
        }
    }
    return 1;
}
int main()
{
    int hx,hy,n;

    node qizi[10];
    //putqipan();
    while(~scanf("%d%d%d",&n,&hx,&hy),n+hx+hy)
    {
        memset(qipan,0,sizeof(qipan));
        for(int i=0;i<n;i++)
        {
            getchar();
            scanf("%c%d%d",&qizi[i].ID,&qizi[i].x,&qizi[i].y);
            qipan[qizi[i].x][qizi[i].y]=-1;
        }
        //putqipan();
        for(int i=0;i<n;i++)
        {
            if(qizi[i].ID=='G'||qizi[i].ID=='R')
            {
                GRlu(qizi[i]);
            }
            else if(qizi[i].ID=='H')
            {
                Hlu(qizi[i]);
            }
            else if(qizi[i].ID=='C')
            {
                Clu(qizi[i]);
            }
            //cout<<endl;
            //putqipan();
        }
        if(judeg(hx,hy)) printf("YES\n");
        else printf("NO\n");
        //putqipan();
    }
    return 0;
}
