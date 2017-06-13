#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char rqy[3][20]={{'0','Q','W','E','R','T','Y','U','I','O','P','0'},
{'0','A','S','D','F','G','H','J','K','L','0'},
{'0','Z','X','C','V','B','N','M','0'}};
int main()
{
    char ch,cmd[10];
    int w;cin>>w;
    getchar();
    while(w--)
    {
        scanf(" %c %s",&ch,cmd);
        int t;
        if(cmd[0]=='R')
            t=1;
        else
            t=-1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<20;j++)
            {
                if(rqy[i][j]==ch)
                {
                    if(rqy[i][j+t]<='Z'&&rqy[i][j+t]>='A')
                        printf("%c\n",rqy[i][j+t]);
                    else
                        printf("No letter.\n");
                    goto go;
                }
            }
        }
        go:;

    }
    return 0;
}
