#include <bits/stdc++.h>

using namespace std;

int main()
{
    double M[11],A;
    int E[33],B;
    char s[100];
    for(int i=0;i<10;i++)
        M[i]=1-pow(0.5,i+1);
    for(int i=0;i<31;i++)
        E[i]=pow(2,i)-1;
    while(scanf("%s",s),strcmp(s,"0e0")==1)
    {
        for(int i=0;i<strlen(s);i++)
            if(s[i]=='e'){s[i]=' ';break;}
        sscanf(s,"%lf %d",&A,&B);
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<31;j++)
            {
                if(fabs((log10(M[i])+E[j]*log10(2))-B-log10(A))<1e-5)
                {
                    printf("%d %d\n",i,j);
                    goto gbreak;
                }
            }
        }
        gbreak:;
    }
    return 0;
}
