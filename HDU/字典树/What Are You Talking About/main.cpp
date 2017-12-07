#include <bits/stdc++.h>

using namespace std;
const int MAX = 26;
struct Trie{
    Trie *next[MAX];
    int k;
    char *str;
    Trie()
    {
        str = NULL;
        k = 0;
        for(int i = 0; i < MAX; i++)
            next[i] = NULL;
    }
};
Trie *root;
int flag;
int judeg(Trie *p)
{
    for(int i = 0; i < MAX; i++)
    {
        if(p->next[i]) return 0;
    }
    return 1;
}
void CerateTrie(char *str,char *str2)
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
        }
        p=p->next[num];
    }
    p->str = new char(15);
    strcpy(p->str,str2);
}
char * FandTrie(char *str)
{
    if(str[0]>'z'||str[0]<'a')
    {
        return NULL;
    }
    int len=strlen(str);
    Trie *p = root;
    for(int i=0;i<len;i++)
    {
        int num = str[i]-'a';
        if(p->next[num]==NULL)
        {
            return NULL;
        }
        p=p->next[num];
    }
    return p->str;
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
    char str1[15],str2[15],str[3005];
    root = new Trie;
    scanf("%s",str1);
    if(!strcmp(str1,"START"))
    {
        while(scanf("%s",str1),strcmp(str1,"END"))
        {
            scanf("%s",str2);
            CerateTrie(str2,str1);
        }
    }
    getchar();
    gets(str);
    if(!strcmp(str,"START"))
    {
        while(gets(str),strcmp(str,"END"))
        {
            int k = 0;
            for(int i=0;i<strlen(str);i++)
            {
                if(str[i]>='a' && str[i]<='z')
                {
                    str1[k++] = str[i];
                }
                else
                {
                    str1[k] = 0;
                    k = 0;
                    char *ans = FandTrie(str1);
                    if(ans == NULL)
                    {
                        printf("%s",str1);
                    }
                    else
                    {
                        printf("%s",ans);
                    }
                    printf("%c",str[i]);
                }

            }
            printf("\n");
            //getchar();
        }
    }
    return 0;
}
