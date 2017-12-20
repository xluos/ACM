//#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
const int MAX = 505;
const int INF = 0x3f3f3f;
int rANK[MAX],pre[MAX],vis[MAX],dis[MAX];
int Chara[MAX][MAX];
int n,m;
struct node{
    int u;  //�����
    int v;  //���յ�
    int w;  //��Ȩֵ
};
vector<node>ve; //�����
bool cmp(node a,node b)
{
    return a.w < b.w;
}
void Init(int n)
{
    for(int i = 0;i < n;i++)
    {
        pre[i] = i;
        rANK[i] = 0;
    }
}

int find_set(int x)
{
    if(pre[x] != x)
    {
        pre[x] = find_set(pre[x]);
    }
    return pre[x];
}
void join(int x,int y)
{
    int fx=find_set(x),fy=find_set(y);
    if(fx != fy)
    {
        if(rANK[fx] >= rANK[fy])
        {
            pre[fx]=fy;
            rANK[fx] += rANK[fy];
        }
        else
        {
            pre[fy]=fx;
            rANK[fx] += rANK[fy];
        }
    }
}
int Kruskal( )
{
    int sum = 0,edge_count = 0;  // sum������С��������Ȩ�ͣ�edge_count�������ߵ�����
    sort(ve.begin(),ve.end(),cmp);  //�߰���Ȩֵ��������
    for(int i=0; i < ve.size() && edge_count < m - 1; i++)  //�߱�������Լ���n-1�����˳�ѭ��
    {
        if(find_set(ve[i].u) != find_set(ve[i].v))  // �����ǰ�߼��벻�ɻ��������ӵ�ǰ��
        {
            join(ve[i].u,ve[i].v);         //��������
            sum += ve[i].w;             //���뵱ǰ�ߵ�Ȩֵ
            edge_count++;            //��¼�ߵ�������һ
        }
    }
    if(edge_count != m - 1)  //���������������n-1 ˵����ͼû����С������
        return -1;
    return sum;       //������С��Ȩ��
}

int Prim(int sre)
{
    int sum = 0;
    int maxx = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < n; i++)
    {
        dis[i] = Chara[sre][i];
    }
    vis[sre] = 1;
    dis[sre] = 0;
    for(int i = 0; i < n - 1; i++)
    {
        int k,minn = INF;
        for(int j = 0;j < n; j++)  //�ҳ�һ����û��ѡ��ľ��뼯��E'����ĵ�
        {
            if(!vis[j]&&dis[j] < minn)
            {
                k = j;
                minn = dis[j];
            }
        }
        if(minn == INF)  //��������С������
        {
            return -1;
        }
        vis[k] = 1;   //���˵���Լ��뼯��E'
        sum += minn;  //���ϵ�ǰ�ߵĺ�
        maxx = max(maxx, minn);
        for(int j = 0; j < n; j++)
        {
            if(!vis[j]&&dis[j] > Chara[k][j])  //���������㵽����E'�ľ���
            {
                dis[j] = Chara[k][j];
            }
        }
    }
    return maxx;
}
int main()
{
    int w;cin>>w;
    while(w--)
    {
        memset(Chara,0x3f,sizeof(Chara));
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                scanf("%d",&Chara[i][j]);
            }
        }
        cout<<Prim(0)<<endl;
    }
}
/*int main()
{
    while(scanf("%d %d",&n,&m),n)
    {
        Init(m + 1);
        for(int i = 0; i < n; i++)
        {

            node ans;
            scanf("%d %d %d",&ans.u,&ans.v,&ans.w);
            ve.push_back(ans);
        }
        int t = Kruskal();
        if(~t)
        {
            printf("%d\n",t);
        }
        else
        {
            printf("?\n");
        }
        ve.clear();
    }

    return 0;
}
*/
