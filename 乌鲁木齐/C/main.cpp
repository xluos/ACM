#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f
int map1[10002][10002],dis[100002],visit[100002];///map1[][]�洢���бߣ�
///dis[]�洢��һ���㵽��i�����·�����ȣ�visit[]�洢����ķ���״̬
int start[100002],end1[100002],num[100005];
const int n=100002;
void dijstra(int s1)
{
    int i,j,pos=1,min1;
    memset(visit,0,sizeof(visit));
    for(i=1;i<=n;++i)
    {
        dis[i]=map1[s1][i];///��һ���㵽�������е�ľ���
    }
    visit[s1]=1;
    dis[s1]=0;
    for(i=1;i<n;i++)///ʣ��n-1���㣬������ȣ�������ȡ����ԭ��� ���·������
    {
        min1=inf;
        for(j=1;j<=n;++j)
        {
            if(!visit[j]&&min1>dis[j])
            {
                min1=dis[j];
                pos=j;
            }
        }///�ҵ���Сdisֵ

        visit[pos]=1;
        for(j=1;j<=n;++j)
        {
            if(!visit[j]&&dis[j]>dis[pos]+map1[pos][j])///1->j�ľ����Ƿ��ͨ��i->pos->j������̣�
            dis[j]=dis[pos]+map1[pos][j];
        }
    }
}
int main()
{
    int ww;
    cin>>ww;
    while(ww--)
    {
        int i,j;
        int t,s=0,d=0;
        int n,m,maxx=0;
        scanf("%d %d",&n,&m);
        memset(map1,inf,sizeof(map1));
        memset(num,0,sizeof(num));
        int a,b,c;
        for(i=0; i<m; ++i) ///��������+Ȩֵ
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a>b) swap(a,b);
            if(-c<map1[a][b])
                map1[a][b]=-c;
            if(num[a]==0)num[a] = -1;
            if(num[b]==0)num[b] = 1;
            if(num[a]==1) num[a] = 2;
            if(num[b]==-1) num[b] = 2;
        }
        int cnt=inf;
        for(int i=0; i<=n; i++)
        {
            cout<<i;
            if(num[i]==-1) start[s++] = i;
            if(num[i]== 1) end1[d++] = i;
        }
cout<<"asdasdasd";
        for(int i=0; i<s; i++)
        {
            dijstra(start[i]);///��ÿ�����ʹ��
            for(int j=0; j<d; j++) ///�󵽶��Ŀ�ĵصľ����е���С
            {
                cnt=cnt>dis[end1[j]]?dis[end1[j]]:cnt;
            }
        }

        printf("%d\n",-cnt);

    }
    return 0;
}

