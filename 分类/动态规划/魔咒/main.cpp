//#include <iostream>
//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//#define N 100005
//using namespace std;
//struct node{
//    char s[25];
//    int l;
//}key[N];
//struct node2{
//    char s[85];
//    int l;
//}tail[N];
//int cmp(node a,node b)
//{
//    return (strcmp(a.s,b.s)<0);
//}
//int cmp2(node2 a,node2 b)
//{
//    return (strcmp(a.s,b.s)<0);
//}
//
//int main()
//{
//
//    int len;char s2[100];
//    for(len=0 ; ; len++)
//    {
//        int i;
//        gets(s2);
//        if(strcmp("@END@",s2)==0)
//            break;
//        int l=strlen(s2);
//        for(i=0;s2[i]!=']';i++)
//        {
//            key[len].s[i]=s2[i];
//        }
//        key[len].s[i]=s2[i++];
//        key[len].s[i++]=0;
//        for(int f=i;f<l;f++)
//            tail[len].s[f-i]=s2[f];
//        tail[len].s[l-i]=0;
//        key[len].l=len;
//        tail[len].l=len;
//    }
//    sort(key,key+len,cmp);
//    for(int j=0;j<len;j++)
//    {
//        tail[key[j].l].l=j;
//    }
//    sort(tail,tail+len,cmp2);
//    for(int j=0;j<len;j++)
//    {
//        key[tail[j].l].l=j;
//    }
////    for(int j=0;j<i;j++)
////    {
////        printf("%d %s %s\n",j,key[j].s,tail[key[j].l].s);
////    }
////    for(int j=0;j<i;j++)
////    {
////        printf("%d %s %s\n",j,tail[j].s,key[tail[j].l].s);
////    }
//
//    int n,l,mid;
//    char s[120];
//    scanf("%d",&n);
//    getchar();
//    for(int j=0;j<n;j++)
//    {
//        gets(s);
//        l=strlen(s);
//        if(s[0]=='[')
//        {
//            node ans;
//            strcpy(ans.s,s);
//            mid=lower_bound(key,key+len,ans,cmp)-key;
//            if(strcmp(ans.s,key[mid].s)==0)
//                printf("%s\n",tail[key[mid].l].s);
//            else
//                printf("what?\n");
//        }
//        else
//        {
//            node2 ans;
//            strcpy(ans.s,s);
//            mid=lower_bound(tail,tail+len,ans,cmp2)-tail;
//            if(strcmp(ans.s,tail[mid].s)==0)
//            {
//                int l=strlen(key[tail[mid].l].s);
//                key[tail[mid].l].s[l-1]=0;
//                printf("%s\n",key[tail[mid].l].s+1);
//            }
//            else
//                printf("what?\n");
//        }
//    }
//    return 0;
//}
//
//
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 100005
using namespace std;
struct node{
    char s1[25];
    char s2[85];
}key[N];
int main()
{

    int i;
    for(i=0 ; ; i++)
    {char s2[120];
        int j;
        gets(s2);
        if(strcmp("@END@",s2)==0)
            break;
        int l=strlen(s2);
        for(j=0;s2[j]!=']';j++)
        {
            key[i].s1[j]=s2[j];
        }
        key[i].s1[j]=s2[j];j++;
        key[i].s1[j]=0;//printf("%s1\n",key[i].s1);
        j++;
        for(int f=j;f<l;f++)
        {
            key[i].s2[f-j]=s2[f];
        }
       //printf("%s2\n",key[i].s2);
       key[i].s2[l-j]=0;
    }
    int n,l,mid;
    char s[110];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        int j;
        int k=1;
        gets(s);
        int len=strlen(s);
        if(s[0]=='[')
        {
            for(j=0;j<i;j++)
            {
                if(strcmp(s,key[j].s1)==0)
                {
                        k=0;
                        break;
                }
            }
            if(k==0)
                printf("%s\n",key[j].s2);
            else
                printf("what?\n");
        }
        else
        {
            for(j=0;j<i;j++)
            {
                if(strcmp(s,key[j].s2)==0)
                {
                        k=0;
                        break;
                }
            }
            int ll=strlen(key[j].s1);
            key[j].s1[ll-1]=0;
            if(k==0)
                printf("%s\n",key[j].s1+1);
            else
                printf("what?\n");
        }
    }
    return 0;
}/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define N 100005
using namespace std;
char spell[N][85];
char magic[N][25];
int num=1;
struct node
{
    int Hash;
    int l;
} key[N],tail[N];
int cmp(node a,node b)
{
    return a.Hash<b.Hash;
}

unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * seed + (*str++);
    }
    return (hash & 0x7FFFFFFF);
}
void init()
{
    for(int i=1; i<num; i++)
    {
        key[i].Hash=BKDRHash(magic[i]);
        key[i].l=i;
        tail[i].Hash=BKDRHash(spell[i]);
        tail[i].l=i;
    }
    sort(key,key+num,cmp);
    sort(tail,tail+num,cmp);
}
int main()
{

    while(scanf("%s",magic[num]))
    {
        if(!strcmp(magic[num],"@END@"))
            break;
        getchar();
        gets(spell[num]);
        num++;
    }
    init();
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        node tmp;
        char str[120];
        gets(str);
        if(str[0]=='[')
        {
            tmp.Hash=BKDRHash(str);
            int mid=lower_bound(key,key+num,tmp,cmp)-key;
            if(key[mid].Hash!=tmp.Hash)
                printf("what?\n");
            else
                printf("%s\n",spell[key[mid].l]);
        }
        else
        {
            tmp.Hash=BKDRHash(str);
            int mid=lower_bound(tail,tail+num,tmp,cmp)-tail;
            if(tail[mid].Hash!=tmp.Hash)
                printf("what?\n");
            else
            {
                int l=strlen(magic[tail[mid].l]);
                magic[tail[mid].l][l-1]=0;
                printf("%s\n",magic[tail[mid].l]+1);
            }
        }
    }
    return 0;
}
*/
