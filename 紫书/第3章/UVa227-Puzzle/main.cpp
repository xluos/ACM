#include <bits/stdc++.h>

using namespace std;
char mn[6][6];
int judge(int &a,int &b,int x,int y)
{
    int px=a+x;
    int py=b+y;
    if(px>=0&&px<5&&py>=0&&py<5)
    {
        mn[a][b]=mn[px][py];
        mn[px][py]=' ';
        a=px;b=py;
        return 1;
    }
    return 0;
}
int main()
{

    int kx,ky,k=1;
    while(1)
    {
        for(int i=0;i<5;i++)
        {
            gets(mn[i]);
            if(strlen(mn[i])==4)
            {
                mn[i][4]=' ';
                mn[i][5]=0;
            }
            for(int j=0;j<5;j++)
            {
                if(mn[i][j]=='Z') return 0;
                if(mn[i][j]==' '){kx=i;ky=j;}
            }
        }
        char ch;int flag=1;
        while(scanf("%c",&ch),ch!='0')
        {
            int px,py;
            switch(ch)
            {
            case 'A':
                if(flag)flag=judge(kx,ky,-1,0);
                break;
            case 'B':
                if(flag)flag=judge(kx,ky,1,0);
                break;
            case 'L':
                if(flag)flag=judge(kx,ky,0,-1);
                break;
            case 'R':
                if(flag)flag=judge(kx,ky,0,1);
                break;
            default : ;
            }
        }
        getchar();
        if(k>1)printf("\n");
        printf("Puzzle #%d:\n",k++);
        if(flag)
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                printf("%c%c",mn[i][j],j==4?'\n':' ');
            }
        }
        else
            printf("This puzzle has no final configuration.\n");
    }
    return 0;
}
