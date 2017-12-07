#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX = 2;
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
        }
        p=p->next[num];
        if(p->k!=0) {flag=1;break;}
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
    int t=1;
    root = new Trie;
    char s[15];
    while(~scanf("%s",s))
    {
        if(s[0]=='9')
        {
            printf("Set %d is %s\n",t++,flag == 0?"immediately decodable":"not immediately decodable");
            flag=0;
            del(root);
            root = new Trie;
        }
        else
        {
            CerateTrie(s);
        }
    }
    return 0;
}
