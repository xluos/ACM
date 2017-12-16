#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;		///数据元素
    struct node *lchild;///指向左孩子节点
    struct node *rchild;///指向右孩子节点
} BTNode;	///声明二叉树节点类型
void CreateBTree(BTNode * &b,char *str)///创建二叉树
{
    BTNode *St[MaxSize],*p;				///St数组作为顺序栈
    int top = -1,k,j = 0;					///Top为栈顶指针
    char ch;
    b = NULL;								///初始时二叉链为空
    ch = str[j];
    while(ch != '\0')						///循环扫描str中的每个字符
    {
        switch(ch)
        {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break;			///开始处理左孩子结点
        case ')':
            top--;
            break;						///栈顶结点的子数处理完毕
        case ',':
            k = 2;
            break;							///开始处理右孩子结点
        default:
            p = (BTNode *)malloc(sizeof(BTNode));	///创建一个结点，由p指向它
            p->data = ch;								///存放结点值
            p->lchild = p->rchild = NULL;				///左，右指针都设置为空
            if(b == NULL)								///若尚未建立根结点
                b = p;								///p所指结点就作为根结点
            else									///已建立二叉树根结点
            {
                switch(k)
                {
                    case 1:
                        St[top]->lchild = p;
                        break;		///新建结点作为栈顶结点的左孩子
                    case 2:
                        St[top]->rchild = p;
                        break;		///新建结点作为栈顶结点的右孩子
                }
            }
        }
        j++;			///继续扫描str
        ch = str[j];
    }
}
void DestroyBTree(BTNode *&b)	///销毁二叉树
{
    if(b != NULL)
    {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}
BTNode * FindNode(BTNode *b,ElemType x)		///查找值为x的结点
{
    BTNode *p;
    if(b == NULL)
        return NULL;
    else if(b->data == x)
        return b;
    else
    {
        p = FindNode(b->lchild,x);
        if(p != NULL)
            return p;
        else
            return FindNode(b->rchild,x);
    }
}
BTNode *LchildNode(BTNode *p)		///返回结点p的左孩子指针
{
    return p->lchild;
}
BTNode *RchildNode(BTNode *p)		///返回结点p的右孩子指针
{
    return p->rchild;
}
int BTHeight(BTNode *b)
{
    int lchildh,rchildh;
    if(b == NULL)return(0);			///空树的高度为0
    else
    {
        lchildh = BTHeight(b->lchild);	///求左子数的高度为lchildh
        rchildh = BTHeight(b->rchild);	///求右子数的高度为rchildh
        return(lchildh>rchildh)?(lchildh+1):(rchildh+1);
    }
}
int BTLeaf(BTNode *b)
{
    if(b == NULL)
        return 0;
    else if(b->lchild == NULL && b->rchild == NULL)
        return 1;
    else
        return(BTLeaf(b->lchild) + BTLeaf(b->rchild) + 1);  ///递归查找两个孩子的节点数，加上自身所以有个+1
}
void DispBTree(BTNode * b)
{
    if(b != NULL)
    {
        printf("%c",b->data);  ///输出节点值
    }
    else
    {
        return ;   ///节点为空是返回，否则下一步运行错误
    }
    if(b->lchild != NULL || b->rchild != NULL)
    {
        printf("(");                ///有孩子结点时才输出“（”
        DispBTree(b->lchild);       ///递归处理左子数
        if(b->rchild != NULL)
        {
            printf(",");            ///有右孩子结点时才输出“）”
        }
        DispBTree(b->rchild);       ///递归处理右子树
        printf(")");                ///有孩子结点时才输出“）”
    }
}
///包含二叉树的基本运算算法
int main()
{
    BTNode * b, * p,* lp,* rp;
    printf("二叉树的基本运算如下：\n");
    printf("  (1)创建二叉树\n");
    CreateBTree(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("  (2)输出二叉树：");
    DispBTree(b);
    printf("\n");
    printf("  (3)H结点：");
    p=FindNode(b,'H');
    if(p != NULL)
    {
        lp = LchildNode(p);
        if(lp != NULL)printf("左孩子为%c",lp->data);
        else printf("无左孩子");
        rp = RchildNode(p);
        if(rp != NULL)printf("右孩子为%c",rp->data);
        else printf("无右孩子");

    }
    printf("\n");
    printf("  (4)二叉树b的高度: %d\n",BTHeight(b));
    printf("  (5)输出二叉树结点个数: %d\n",BTLeaf(b));
    printf("  (6)释放二叉树 b\n");
    DestroyBTree(b);
    printf("李静玉161360342");
    return 1;
}



/*#include <bits/stdc++.h>

using namespace std;
const int MAX = 26;
struct Trie{
    Trie *next[MAX];
    int k;
    Trie()
    {
        k = 0;
        for(int i = 0; i < MAX; i++)
            next[i] = NULL;
    }
};
Trie *root;
int flag,sum;

void CerateTrie(char *str)
{
    int len=strlen(str);
    Trie *p = root;
    for(int i=0;i<len;i++)
    {
        int num = str[i]-'a';
        if(p->next[num]==NULL)
        {
            p->next[num] = new Trie;
            p->next[num]->k = 0;
            sum++;
        }
        p=p->next[num];
    }
}

void del(Trie *p)
{
    for(int i=0;i<MAX;i++)
    {
        if(p->next[i]) del(p->next[i]);
    }
    delete(p);
}
int main()
{
    int n,maxx;
    char str[55];
    while(~scanf("%d",&n))
    {
        maxx = 0;
        sum = 0;
        root = new Trie;
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            int ans = strlen(str);
            maxx = max(ans,maxx);
            CerateTrie(str);
        }
        printf("%d\n",sum*2 + n - maxx);
        del(root);
    }
    return 0;
}
*/
