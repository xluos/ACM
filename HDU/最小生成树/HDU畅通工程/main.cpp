#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;
int rANK[MAX],pre[MAX];
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


int main()
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
