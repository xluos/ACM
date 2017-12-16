#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
    ElemType data;		///����Ԫ��
    struct node *lchild;///ָ�����ӽڵ�
    struct node *rchild;///ָ���Һ��ӽڵ�
} BTNode;	///�����������ڵ�����
void CreateBTree(BTNode * &b,char *str)///����������
{
    BTNode *St[MaxSize],*p;				///St������Ϊ˳��ջ
    int top = -1,k,j = 0;					///TopΪջ��ָ��
    char ch;
    b = NULL;								///��ʼʱ������Ϊ��
    ch = str[j];
    while(ch != '\0')						///ѭ��ɨ��str�е�ÿ���ַ�
    {
        switch(ch)
        {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break;			///��ʼ�������ӽ��
        case ')':
            top--;
            break;						///ջ�����������������
        case ',':
            k = 2;
            break;							///��ʼ�����Һ��ӽ��
        default:
            p = (BTNode *)malloc(sizeof(BTNode));	///����һ����㣬��pָ����
            p->data = ch;								///��Ž��ֵ
            p->lchild = p->rchild = NULL;				///����ָ�붼����Ϊ��
            if(b == NULL)								///����δ���������
                b = p;								///p��ָ������Ϊ�����
            else									///�ѽ��������������
            {
                switch(k)
                {
                    case 1:
                        St[top]->lchild = p;
                        break;		///�½������Ϊջ����������
                    case 2:
                        St[top]->rchild = p;
                        break;		///�½������Ϊջ�������Һ���
                }
            }
        }
        j++;			///����ɨ��str
        ch = str[j];
    }
}
void DestroyBTree(BTNode *&b)	///���ٶ�����
{
    if(b != NULL)
    {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}
BTNode * FindNode(BTNode *b,ElemType x)		///����ֵΪx�Ľ��
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
BTNode *LchildNode(BTNode *p)		///���ؽ��p������ָ��
{
    return p->lchild;
}
BTNode *RchildNode(BTNode *p)		///���ؽ��p���Һ���ָ��
{
    return p->rchild;
}
int BTHeight(BTNode *b)
{
    int lchildh,rchildh;
    if(b == NULL)return(0);			///�����ĸ߶�Ϊ0
    else
    {
        lchildh = BTHeight(b->lchild);	///���������ĸ߶�Ϊlchildh
        rchildh = BTHeight(b->rchild);	///���������ĸ߶�Ϊrchildh
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
        return(BTLeaf(b->lchild) + BTLeaf(b->rchild) + 1);  ///�ݹ�����������ӵĽڵ������������������и�+1
}
void DispBTree(BTNode * b)
{
    if(b != NULL)
    {
        printf("%c",b->data);  ///����ڵ�ֵ
    }
    else
    {
        return ;   ///�ڵ�Ϊ���Ƿ��أ�������һ�����д���
    }
    if(b->lchild != NULL || b->rchild != NULL)
    {
        printf("(");                ///�к��ӽ��ʱ�����������
        DispBTree(b->lchild);       ///�ݹ鴦��������
        if(b->rchild != NULL)
        {
            printf(",");            ///���Һ��ӽ��ʱ�����������
        }
        DispBTree(b->rchild);       ///�ݹ鴦��������
        printf(")");                ///�к��ӽ��ʱ�����������
    }
}
///�����������Ļ��������㷨
int main()
{
    BTNode * b, * p,* lp,* rp;
    printf("�������Ļ����������£�\n");
    printf("  (1)����������\n");
    CreateBTree(b,"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
    printf("  (2)�����������");
    DispBTree(b);
    printf("\n");
    printf("  (3)H��㣺");
    p=FindNode(b,'H');
    if(p != NULL)
    {
        lp = LchildNode(p);
        if(lp != NULL)printf("����Ϊ%c",lp->data);
        else printf("������");
        rp = RchildNode(p);
        if(rp != NULL)printf("�Һ���Ϊ%c",rp->data);
        else printf("���Һ���");

    }
    printf("\n");
    printf("  (4)������b�ĸ߶�: %d\n",BTHeight(b));
    printf("  (5)���������������: %d\n",BTLeaf(b));
    printf("  (6)�ͷŶ����� b\n");
    DestroyBTree(b);
    printf("���161360342");
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
