#include <bits/stdc++.h>
int pre[100001];
int find(int x)
{
    int r=x;
   while (pre[r ]!=r)
   r=pre[r ];
   int i=x; int j;
   while(i!=r)
   {
       j=pre[i ];
       pre[i ]=r;
       i=j;
   }
   return r;
}
int main()
{
   int n,m,p1,p2,i,total,f1,f2;
   while(~scanf("%d %d",&n,&m))         //读入n，如果n为0，结束
   {                                                    //刚开始的时候，有n个城镇，一条路都没有 //那么要修n-1条路才能把它们连起来
       total=n-1;
       //每个点互相独立，自成一个集合，从1编号到n //所以每个点的上级都是自己
       for(i=1;i<=n;i++) { pre[i]=i; }                //共有m条路
       while(m--)
       { //下面这段代码，其实就是join函数，只是稍作改动以适应题目要求
           //每读入一条路，看它的端点p1，p2是否已经在一个连通分支里了
           scanf("%d %d",&p1,&p2);
           f1=find(p1);
           f2=find(p2);
               //如果是不连通的，那么把这两个分支连起来
               //分支的总数就减少了1，还需建的路也就减了1
           if(f1!=f2)
            {
               pre[f2 ]=f1;
               total--;
           }
           //如果两点已经连通了，那么这条路只是在图上增加了一个环 //对连通性没有任何影响，无视掉
       }
//最后输出还要修的路条数
       printf("%d\n",total);
   }
   return 0;
}
