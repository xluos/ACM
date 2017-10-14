#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[5];
bool cmp(char a,char b)
{
    return a>b;
}
int getmax(char s[])
{
    sort(s,s+strlen(s),cmp);
    int n;
    sscanf(s,"%d",&n);
    return n;
}
int getmin(char s[])
{
    sort(s,s+strlen(s));
    int n;
    sscanf(s,"%d",&n);
    return n;
}
void getstr(int n,char *s)
{
    sprintf(s,"%d",n);
}
int main()
{

    while(scanf("%s",s))
    {
        if(!strcmp(s,"-1")) break;
        printf("N=%s:\n",s);
        int minn,maxx,t=0;
        sort(s,s+strlen(s));
        if(s[0]!=s[3]&&strlen(s) == 4)
        while(1)
        {
            minn = getmin(s);
            maxx = getmax(s);
            printf("%d-%d=%d\n",maxx,minn,maxx-minn);
            t++;
            if(maxx-minn == 0||maxx-minn == 6174) break;
            getstr(maxx-minn,s);
        }
        if(t)
        {
            printf("Ok!! %d times\n",t);
        }
        else
        {
            printf("No!!\n");
        }
    }
    return 0;
}
