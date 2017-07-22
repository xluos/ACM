#include <bits/stdc++.h>

using namespace std;

int main()
{
    char shou[11][5],yan[11][5],kou[11][5],s[100];
    int ss=0,y=0,kk=0;
    gets(s);
    s[5]=0;
    for(int i=0,k=0;i<strlen(s);i++)
    {
        printf("%s",s+1);
        if(s[i]=='[')
        {
            i++;
            for(k=0;s[i+1]!=']';k++,i++)
                shou[ss][k]=s[i];
            shou[ss][k]=0;
            ss++;
        }
    }
    gets(s);
    for(int i=0,k=0;i<strlen(s);i++)
    {
        if(s[i]=='[')
        {
            i++;
            for(k=0;s[i+1]!=']';k++,i++)
                yan[y][k]=s[i];
            yan[y][k]=0;
            y++;
        }
    }
    gets(s);
    for(int i=0,k=0;i<strlen(s);i++)
    {
        if(s[i]=='[')
        {
            i++;
            for(k=0;s[i+1]!=']';k++,i++)
                kou[kk][k]=s[i];
            kou[kk][k]=0;
            kk++;
        }
    }
    int n,m[6];
    cin>>n;
    while(n--)
    {
        int flag=1;
        for(int i=0;i<5;i++)
        {
            cin>>m[i];
            if(m[i]<0)
                flag=0;
        }
        if(m[0]<ss&&m[4]<ss&&m[1]<y&&m[3]<y&&m[2]<kk&&flag)
        {
            printf("%s(%s%s%s)%s\n",shou[m[0]],yan[m[1]],kou[m[2]],yan[m[3]],shou[m[4]]);
        }
        else
        {
            printf("Are you kidding me? @\/@\n");
        }
    }

    return 0;
}
