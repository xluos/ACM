
#include <iostream>
#include <stdio.h>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
char op[]={'=', '(', '+', '-', '*', '/', ')'};
int lpri[]={0,1,3,3,5,5,6},rpri[]={0,6,2,2,4,4,1};
map<char,int>rop,lop;
char ss[1005];
int flag=0;
int init_op()
{
    for(int i=0;i<7;i++)
    {
        rop[op[i]]=rpri[i];
        lop[op[i]]=lpri[i];
    }
}
int judge(char ch)
{
    if(ch>='0'&&ch<='9'||ch=='.')
        return 1;
    return 0;
}
void z_h(char s[])
{
    int l=strlen(s);
    double ans;
    int t=0;
    stack<char>op;
    op.push('=');
    stack<int>s_num;
    for(int i=0;i<l;i++)
    {

        if(judge(s[i]))
        {
            ans=0;
            for(int j=i;judge(s[i]);i++)
            {
                ss[t++]=s[i];
            }
            ss[t++]=' ';
        }
        if(rop[s[i]]>lop[op.top()])
            op.push(s[i]);
        else
        {
            while(rop[s[i]]<=lop[op.top()])
            {
                char ch=op.top();
                op.pop();
                if(ch=='('||ch=='=')break;
                ss[t++]=ch;
                //ss+=' ';
            }
            if(s[i]!=')')
            op.push(s[i]);
        }

    }

}
double jisuan(char s[])
{
    int l=strlen(s);
    double ans;
    char sa[1000];
    stack<double>s_num;
    for(int i=0;i<l;i++)
    {

        if(judge(s[i]))
        {
            ans=0;int t=0;
            for(int j=i;judge(s[i]);i++)
            {
                sa[t++]=s[i];
            }
            sa[t]=0;
            sscanf(sa,"%lf",&ans);
            s_num.push(ans);
        }
        else
        {
            if(s[i]==' ')
                continue;
            switch(s[i])
            {
                double a,b;
                case '+':
                    b=s_num.top();
                    s_num.pop();
                    a=s_num.top();
                    s_num.pop();
                    s_num.push(a+b);
                    break;
                case '-':
                    b=s_num.top();
                    s_num.pop();
                    a=s_num.top();
                    s_num.pop();
                    s_num.push(a-b);
                    break;
            }
        }
    }
    return s_num.top();
}
int dian(char s[])
{
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]=='.')
            return 1;
    }
    return 0;
}
int main()
{
    init_op();
    int w;cin>>w;
    getchar();
    char s[1009];
    gets(s);
    int l=strlen(s);
    s[l]='=';
    s[l+1]=0;
    z_h(s);
    flag=dian(s);
    if(flag)
        printf("%.6lf\n",jisuan(ss));
    else
        printf("%lld\n",(long long int)jisuan(ss));
    return 0;
}
