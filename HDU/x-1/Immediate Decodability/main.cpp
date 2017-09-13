#include <bits/stdc++.h>

using namespace std;
struct Trie
{
    Trie *M[2];
    int k;
    Trie(){
        M[0]=M[1]=NULL;
        k=0;
    }
};
char s[15];
Trie *root = new Trie;
int CreateTrie(char *str)
{
    int l = strlen(str);
    Trie *p = root;
    for(int i = 0;i < l;i++)
    {
        int num = str[i] - '0';
        if(p->k) return 1;
        if(p->M[num]==NULL)
        {
            p->M[num] = new Trie;
        }
        p = p->M[num];
    }
    if(p->M[0] != NULL || p->M[1] != NULL || p->k) {return 1;}
    p->k = 1;
    return 0;
}
int main()
{
    int t=1,flag=0;
    while(~scanf("%s",s))
    {
        if(s[0]=='9')
        {
            printf("Set %d is %s\n",t++,!flag?"immediately decodable":"not immediately decodable");
            flag=0;
        }
        else
        {
            if(flag) continue;
            flag=CreateTrie(s);
        }
    }
    return 0;
}
