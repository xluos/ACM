#include <stdio.h>
#include <string.h>

using namespace std;
struct Trie{
    Trie *m[26];
    int num;
    Trie(){
        num=0;
        for(int i=0;i<26;i++)
        {
            m[i]=NULL;
        }
    }
};
int flag=1;
Trie *root = new Trie;
int CerterTrie(char *str)
{
    int l=strlen(str);
    Trie *p = root;
    for(int i=0;i < l;i++)
    {
        int k = str[i]-'a';
        if(p->m[k]==NULL)
        {
            p->m[k] = new Trie;
        }
        p = p->m[k];
        if(flag) p->num++;
    }
    return p->num;
}
int main()
{
    char s[10];
    while(gets(s))
    {
        if(flag&&strlen(s))
        {
            CerterTrie(s);
        }
        else
        {
            if(!flag) printf("%d\n",CerterTrie(s));
            else flag=0;
        }
    }
    return 0;
}
