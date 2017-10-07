#include <bits/stdc++.h>

using namespace std;
int px(int dx,int n)
{
    if(n==0) return 0;
    if(n==1) return dx;
    return px(dx,n-1)*10+dx;
}
int main()
{
    char s[100],s2[100],Da,Db;
    scanf("%s %c %s %c",s,&Da,s2,&Db);
    printf("%d\n",px(Da-'0',count(s,s+strlen(s),Da))+px(Db-'0',count(s2,s2+strlen(s2),Db)));
    return 0;
}
