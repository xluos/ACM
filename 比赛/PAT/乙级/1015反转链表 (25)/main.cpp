#include <bits/stdc++.h>

using namespace std;
struct node
{
    int data,next;
} mp[100005];
struct node2
{
    int id,data,next;
};
int main()
{
    int head,n,k,ans,flag=1;
    vector<node2>ve;
    stack<node2>st;
    cin>>head>>n>>k;
    for(int i=0; i<n; i++)//储存节点
    {
        scanf("%d",&ans);
        scanf("%d %d",&mp[ans].data,&mp[ans].next);
    }
    ans=head;
    n=1;
    while(1)
    {
        if(mp[ans].next!=-1)//遍历链表统计N
        {
            ans=mp[ans].next;
            n++;
        }
        else
        {
            break;
        }
    }
    do
    {
            for(int i=0; i<k; i++)
            {
                node2 p;
                p.data=mp[head].data;
                p.id=head;
                p.next=mp[head].next;
                st.push(p);//存入栈中
                head=mp[head].next;
            }
            while(!st.empty())
            {
                ve.push_back(st.top());//反转放入vector
                st.pop();
            }
            n-=k;
    }while(n>=k);
    while(n)//n>0且不足k个的直接放入vector
    {
        node2 p;
        p.data=mp[head].data;
        p.id=head;
        p.next=mp[head].next;
        ve.push_back(p);
        if(p.next==-1)break;
        else head=p.next;
    }
    for(int i=0;i<ve.size();i++)//输出
    {
        printf("%05d %d ",ve[i].id,ve[i].data);
        if(i==ve.size()-1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%05d\n",ve[i+1].id);
        }
    }
    return 0;
}
/**
    00100 4 4
    00100 3 12345
    12345 1 12121
    12121 5 13131
    13131 6 -1

00100 1 1
00100 1 -1
*/
