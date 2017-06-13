//#include <cmath>
//#include <cstring>
//#include <cstdio>
//using namespace std;
//int maxn = 0;
//struct trie
//{
//    int cnt;
//    trie* child[26];
//    trie(){
//        cnt=0;
//        memset(child,0,sizeof(child));
//    }
//};
//trie* root = new trie;
//char str[20];
//char aimstr[20];
//void insert(char* str)
//{
//    char* p = str;
//    trie *k=root;
//    while(*p)
//    {
//        int key = *p - 'a';
//        if(k->child[key] == 0)
//        {
//            trie* np = new trie;
//            np->cnt = 0;
//            k -> child[key] = np;
//        }
//        k =k->child[key];
//        p++;
//    }
//    k->cnt++;
//    if(maxn <k -> cnt)
//    {
//        maxn = k -> cnt;
//        strcpy(aimstr,str);
//    }
//}
//int main()
//{
//
//    int n;
//    scanf("%d",&n);
//    for(int i = 0;i < n;i++)
//    {
//        scanf("%s",str);
//        insert(str);
//    }
//    printf("%s %d\n",aimstr,maxn);
//    return 0;
//}




#include <cstdio>
#include <string.h>
#include <stdlib.h>
#define MAX 26
struct Trie
{
    Trie *next[MAX];
    int v;   //根据需要变化
    Trie(){
    v = 0;
    for(int i=0;i<26;i++)
        next[i]=NULL;
    }
};
char ss[19];
int maxx=-1;
Trie *root=new Trie;
void createTrie(char *str)
{
    int len = strlen(str);
    Trie *p = root;
    for(int i=0; i<len; ++i)
    {
        int id = str[i]-'a';
        if(p->next[id] == NULL)
        {
            Trie *q = new Trie;
            q->v = 0;
            p->next[id] = q;
            p = p->next[id];
        }
        else
        {

            p = p->next[id];
        }
    }
    p->v++;
    if (p->v>maxx)
    {
        maxx=p->v;
        strcpy(ss,str);
    }
}
int main()
{
    int w;scanf("%d",&w);
    char s[11];
    while(w--)
    {
        scanf("%s",s);
        createTrie(s);
    }
    printf("%s %d\n",ss,maxx);
}



//
//
//
//
//
//
//
//
//
//
//
//
////#include <iostream>
////#include <stdio.h>
////#include <map>
////#include <cstring>
////#include <string>
////using namespace std;
////
////int main()
////{
////    map<string,int>mp;
////    int n,maxx=-1;
////    string s,ans;
////    cin>>n;
////    while(n--)
////    {
////        cin>>s;
////        if(++mp[s]>maxx)
////        {
////            maxx=mp[s];
////            ans=s;
////        }
////    }
////    cout<<ans<<' '<<maxx<<endl;
////    return 0;
////}
