#include <bits/stdc++.h>

using namespace std;
const int MAX = 100001;

int rank[MAX],pre[MAX];

int index;
void init(int n)
{
    index = n;
    for(int i = 0;i < n;i++)
        pre[i] = index++;
    for(int i=n;i < 2*n;i++)
        pre[i] = i;
}

void del(int n)
{
    pre[n] = index;
    pre[index] = index++ ;
}
//递归写法
int find(int x)
{
    if(pre[x] != x)
    {
        pre[x] = find(pre[x]);
    }
    return pre[x];
}
// 非递归写法
int find_2(int x)
{
    int r=x;
    while(r!=pre[r])
        r=pre[r];

    int i=x,j;
    while(pre[i]!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
// rank[]初始化是都为0或1，代表手下的人数
void join_1(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx != fy)
    {
        if(rank[fx] >= rank[fy])
        {
            pre[fx]=fy;
            rank[fx] += rank[fy];
        }
        else
        {
            pre[fy]=fx;
            rank[fx] += rank[fy];
        }
    }
}
void join_2(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
    pre[fx ]=fy;
}
int main()
{
    int n;
    cin>>n;
    init(n);

    return 0;
}
