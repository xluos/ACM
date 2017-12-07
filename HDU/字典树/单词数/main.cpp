#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
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
int maxx=0;
void CerterTrie(Trie *root,string str)
{
    int l=str.size();
    Trie *p = root;
    for(int i=0;i < l;i++)
    {
        int k = str[i]-'a';
        if(p->m[k]==NULL)
        {
            p->m[k] = new Trie;
        }
        p = p->m[k];
    }
    if(!p->num) maxx++;
    p->num = 1;
}
int main()
{
    string s;
    while(getline(cin,s))
    {
        Trie *root = new Trie;
        if(s=="#"&&s.size()==1) break;
        stringstream ss(s);
        while(ss>>s)
            CerterTrie(root,s);
        printf("%d\n",maxx);
        maxx=0;
    }
    return 0;
}
