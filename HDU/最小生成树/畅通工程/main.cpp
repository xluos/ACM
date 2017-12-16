/************************************************************************
CSDN 勿在浮沙筑高台 http://blog.csdn.net/luoshixian099算法导论--最小生成树（Prim、Kruskal）2016年7月14日
************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 6  //顶点数量
char vextex[] = { 'A', 'B', 'C', 'D', 'E', 'F' };

typedef struct  //邻接链表
{
    int u;
    int v;
    unsigned int cost;  //边的代价
}Arc;  //原始图的边信息

void AdjMatrix(unsigned int adjMat[][MAX])  ///邻接矩阵表示法    就是建图
{
    for (int i = 0; i < MAX; i++)   //初始化邻接矩阵
        for (int j = 0; j < MAX; j++)
        {
            adjMat[i][j] = INF;
        }
    adjMat[0][1] = 6; adjMat[0][2] = 1; adjMat[0][3] = 5;
    adjMat[1][0] = 6; adjMat[1][2] = 5; adjMat[1][4] = 3;
    adjMat[2][0] = 1; adjMat[2][1] = 5; adjMat[2][3] = 5; adjMat[2][4] = 6; adjMat[2][5] = 4;
    adjMat[3][0] = 5; adjMat[3][2] = 5; adjMat[3][5] = 2;
    adjMat[4][1] = 3; adjMat[4][2] = 6; adjMat[4][5] = 6;
    adjMat[5][2] = 4; adjMat[5][3] = 2; adjMat[5][4] = 6;
}
int Minmum(struct node * closedge)  //返回最小代价边
{
    unsigned int min = INF;
    int index = -1;
    for (int i = 0; i < MAX;i++)
    {
        if (closedge[i].lowestcost < min && closedge[i].lowestcost !=0)
        {
            min = closedge[i].lowestcost;
            index = i;
        }
    }
    return index;
}
void MiniSpanTree_Prim(unsigned int adjMat[][MAX], int s)
{
    for (int i = 0; i < MAX;i++)
    {
        closedge[i].lowestcost = INF;
    }
    closedge[s].data = s;      //从顶点s开始
    closedge[s].lowestcos
    for (int i = 0; i < MAX;i++)  //初始化辅助数组
    {
        if (i != s)
        {
            closedge[i].data = s;
            closedge[i].lowestcost = adjMat[s][i];
        }
    }
    for (int e = 1; e <= MAX -1; e++)  //n-1条边时退出
    {
        int k = Minmum(closedge);  //选择最小代价边
        cout << vextex[closedge[k].data] << "--" << vextex[k] << endl;//加入到最小生成树
        closedge[k].lowestcost = 0; //代价置为0
        for (int i = 0; i < MAX;i++)  //更新v中顶点最小代价边信息
        {
            if ( adjMat[k][i] < closedge[i].lowestcost)
            {
                closedge[i].data = k;
                closedge[i].lowestcost = adjMat[k][i];
            }
        }
    }
}
void ReadArc(unsigned int  adjMat[][MAX],vector<Arc> &vertexArc) //保存图的边代价信息
{
    Arc * temp = NULL;
    for (unsigned int i = 0; i < MAX;i++)
    {
        for (unsigned int j = 0; j < i; j++)
        {
            if (adjMat[i][j]!=INF)
            {
                temp = new Arc;
                temp->u = i;
                temp->v = j;
                temp->cost = adjMat[i][j];
                vertexArc.push_back(*temp);
            }
        }
    }
}
bool compare(Arc  A, Arc  B)
{
    return A.cost < B.cost ? true : false;
}
bool FindTree(int u, int v,vector<vector<int> > &Tree)
{
    unsigned int index_u = INF;
    unsigned int index_v = INF;
    for (unsigned int i = 0; i < Tree.size();i++)  //检查u,v分别属于哪颗树
    {
        if (find(Tree[i].begin(), Tree[i].end(), u) != Tree[i].end())
            index_u = i;
        if (find(Tree[i].begin(), Tree[i].end(), v) != Tree[i].end())
            index_v = i;
    }

    if (index_u != index_v)   //u,v不在一颗树上，合并两颗树
    {
        for (unsigned int i = 0; i < Tree[index_v].size();i++)
        {
            Tree[index_u].push_back(Tree[index_v][i]);
        }
        Tree[index_v].clear();
        return true;
    }
    return false;
}
void MiniSpanTree_Kruskal(unsigned int adjMat[][MAX])
{
    vector<Arc> vertexArc;
    ReadArc(adjMat, vertexArc);//读取边信息
    sort(vertexArc.begin(), vertexArc.end(), compare);//边按从小到大排序
    vector<vector<int> > Tree(MAX); //6棵独立树
    for (unsigned int i = 0; i < MAX; i++)
    {
        Tree[i].push_back(i);  //初始化6棵独立树的信息
    }
    for (unsigned int i = 0; i < vertexArc.size(); i++)//依次从小到大取最小代价边
    {
        int u = vertexArc[i].u;
        int v = vertexArc[i].v;
        if (FindTree(u, v, Tree))//检查此边的两个顶点是否在一颗树内
        {
            cout << vextex[u] << "---" << vextex[v] << endl;//把此边加入到最小生成树中
        }
    }
}

int main()
{
    unsigned int  adjMat[MAX][MAX] = { 0 };
    AdjMatrix(adjMat);   //邻接矩阵
    cout << "Prim :" << endl;
    MiniSpanTree_Prim(adjMat,0); //Prim算法，从顶点0开始.
    cout << "-------------" << endl << "Kruskal:" << endl;
    MiniSpanTree_Kruskal(adjMat);//Kruskal算法
    return 0;
}
