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
string z_h(char s[])
{
    int l=strlen(s);
    double ans;
    string ss;
    stack<char>op;
    op.push('=');
    stack<int>s_num;
    for(int i=0;i<l;i++)
    {

        if(judge(s[i]))
        {
            ans=0;//ss.clear();
            for(int j=i;judge(s[i]);i++)
            {
                ss+=s[i];
            }
            ss+=' ';

        }
        if(rop[s[i]]>lop[op.top()])
        {
            op.push(s[i]);
        }
        else
        {
            while(rop[s[i]]<=lop[op.top()])
            {
                char ch=op.top();
                op.pop();
                if(ch=='('||ch=='=')break;
                ss+=ch;
                ss+=' ';
            }
            if(s[i]!=')')
            op.push(s[i]);
        }

    }
    return ss+'=';

}
int main()
{
    init_op();
    int w;cin>>w;
    getchar();
    char s[1000];
    while(w--)
    {
        gets(s);
        cout<<z_h(s)<<endl;
    }
    return 0;
}
