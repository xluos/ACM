#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
int a[10000005];
int b[100005];
int main()
{
    map<char,int> m_c;
    m_c['A']=2;
    m_c['B']=2;
    m_c['C']=2;
    m_c['D']=3;
    m_c['E']=3;
    m_c['F']=3;
    m_c['G']=4;
    m_c['H']=4;
    m_c['I']=4;
    m_c['J']=5;
    m_c['K']=5;
    m_c['L']=5;
    m_c['M']=6;
    m_c['N']=6;
    m_c['O']=6;
    m_c['P']=7;
    m_c['R']=7;
    m_c['S']=7;
    m_c['T']=8;
    m_c['U']=8;
    m_c['V']=8;
    m_c['W']=9;
    m_c['X']=9;
    m_c['Y']=9;
    int n;
    scanf("%d",&n);
    {
        //map<int,int>m_s;
        int flag=1;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int str,t=0;
        char c;
        getchar();
        while(n--)
        {
            int k=0,str=0;
            while(1)
            {

                scanf("%c",&c);
                if(c=='\n')break;
                if(c>='0'&&c<='9')
                    str=str*10+c-'0';
                else if(c>='A'&&c<'Z'&&c!='Q')
                    str=str*10+(m_c[c]);
                else
                    continue;
            }
            if(!a[str])
                b[t++]=str;
            a[str]++;
        }
        sort(b,b+t);
        for(int i=0;i<t;i++)
        {
            if(a[b[i]]>1)
            {
                flag=0;
                char s[20];
                sprintf(s,"%07d",b[i]);
                for(int i=0;i<8;i++)
                {
                    if(i==3)
                        printf("-");
                    printf("%c",s[i]);
                }
                printf(" %d\n",a[b[i]]);
            }
        }
        if(flag)
            printf("No duplicates.\n");

    }
    return 0;
}
