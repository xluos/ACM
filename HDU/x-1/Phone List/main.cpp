#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int MAX = 10;
struct Trie{
    Trie *next[MAX];
    int k;
    Trie()
    {
        k=0;
        for(int i=0;i<MAX;i++)
            next[i] = NULL;
    }
};
Trie *root;
int flag;
int judeg(Trie *p)
{
    for(int i=0;i<MAX;i++)
    {
        if(p->next[i]) return 0;
    }
    return 1;
}
void CerateTrie(char *str)
{
    if(flag) return ;
    int len=strlen(str);
    Trie *p = root;
    for(int i=0;i<len;i++)
    {
        int num = str[i]-'0';
        if(p->next[num]==NULL)
        {
            p->next[num] = new Trie;
            p->next[num]->k = 0;
        }
        p=p->next[num];
        if(p->k!=0) flag=1;
    }
    if(!judeg(p))flag = 1;
    p->k = 1;
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
    int w;
    scanf("%d",&w);
    while(w--)
    {
        int n;
        char str[11];
        root = new Trie;
        root->k = 0;
        flag=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            CerateTrie(str);
        }
        if(flag) printf("NO\n");
        else printf("YES\n");
        del(root);
    }
    return 0;
}
