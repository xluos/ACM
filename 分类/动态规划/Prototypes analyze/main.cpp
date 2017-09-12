#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct Tree
{
    struct Tree *lchild,*rchild;
    int key;
};
int Insert(Tree *&p,int k)
{
    if(p==NULL)
    {
        p = (Tree*)malloc(sizeof(Tree));
        p->key=k;
        p->lchild=p->rchild=NULL;
        return 1;
    }
    else if(k<p->key)
        return Insert(p->lchild,k);
    else if(k>p->key)
        return Insert(p->rchild,k);
}
Tree *CreatT(int A[],int n)
{
    Tree *tr = NULL;
    int i=0;
    while(i<n)
    {
        Insert(tr,A[i]);
        i++;
    }
    return tr;
}
bool Like(Tree *b1,Tree *b2)
{
    bool like1,like2;
    if(b1==NULL&&b2==NULL)
        return true;
    else if(b1==NULL||b2==NULL)
        return false;
    else
    {
        like1=Like(b1->lchild,b2->lchild);
        like2=Like(b1->rchild,b2->rchild);
        return (like1&&like2);
    }
}
int main()
{
    int T;scanf("%d",&T);
    while(T--)
    {
        int n,k;
        int a[25];
        Tree *tr[55];
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                scanf("%d",&a[j]);
            }
            tr[i]=CreatT(a,k);
        }
        int sum=0,s=-1;
        int vis[55];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            if(vis[i])continue;
            s=0;
            vis[i]=1;
            for(int j=0;j<n;j++)
            {
                if(i!=j&&Like(tr[i],tr[j])&&!vis[j])
                {
                   // printf("%d %d\n",i,j);
                    vis[j]=1;
                    s++;
                }
            }

            sum=sum+s;

        }
//        printf("%d\n",sum);
//        for(int i=0;i<n;i++)
//            cout<<vis[i]<<' '<<endl;
        cout<<n-sum<<endl;
    }
    return 0;
}
