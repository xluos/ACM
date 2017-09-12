#include <iostream>
#include <stack>
#include <cstdio>
#include <map>
#include <string>
#include <sstream>


using namespace std;
struct node{
int num;
int ge;
};
map<char,int> lpri;
map<char,int> rpri;
stack<char> op;
stack<string> postexp;
stack<string> postexp1;
stack<node> postexpnum;
int main()
{
    lpri['=']=0;
    lpri['(']=1;
    lpri['+']=3;
    lpri[')']=6;
    lpri[',']=1.5;

    rpri['=']=0;
    rpri['(']=6;
    rpri['+']=2;
    rpri[')']=1;
    rpri[',']=2,5;
    int N;
    cin>>N;
    while(N--)
    {
        string str;
        cin>>str;
        str=str+"=";
       // cout<<str<<endl;;
        op.push('=');
        string tmpnum;
        for(unsigned int i = 0;i<str.length();i++)
        {
            if(str[i]=='M'||str[i]=='A'||str[i]=='X')
                continue;
            if(rpri.count(str[i]))
            {
                if(tmpnum.length()!=0)
                {
                    postexp.push(tmpnum);
                    tmpnum.clear();
                }
                if(rpri[str[i]]>lpri[op.top()])
                {
                    op.push(str[i]);
                }
                else
                {
                    if(str[i]==')')
                    {
                        while(op.top()!='(')
                        {
                            string str1;
                            str1+=op.top();
                            op.pop();
                            postexp.push(str1);
                        }
                        op.pop();
                    }
                    else
                    {
                        while(lpri[op.top()]>rpri[str[i]])
                        {
                            string str1;
                            str1+=op.top();
                            op.pop();
                            postexp.push(str1);
                        }
                        op.push(str[i]);
                    }
                }
            }
             else
                {
                    tmpnum+=str[i];
                }
        }
        while(!postexp.empty())
        {
            //cout<<postexp.top();
             postexp1.push(postexp.top());
             postexp.pop();
        }
        while(!postexp1.empty())
        {
            struct node num1,num2;
            stringstream ss;
            if(postexp1.top()=="+")
            {
                num1=postexpnum.top();
                postexpnum.pop();
               // num1.num+=postexpnum.top().num;
               // num1.ge+=postexpnum.top().ge+1;
                num2=postexpnum.top();
                postexpnum.pop();
                num1.num+=num2.num;
                num1.ge+=num2.ge+1;
             //   cout<<num1.num<<"  "<<num1.ge<<endl;
                postexpnum.push(num1);
            }
            else if(postexp1.top()==",")
            {
                num1=postexpnum.top();
                postexpnum.pop();
                num2=postexpnum.top();
                postexpnum.pop();
                if(num1.num>=num2.num)
                {
                    num1.ge=num1.ge*2+num2.ge;
                   // cout<<num1.num<<"   num1"<<num1.ge<<endl;
                    postexpnum.push(num1);
                }
                else
                {
                     num2.ge=num2.ge*2+num1.ge;
                    //  cout<<num2.num<<"   num2"<<num2.ge<<endl;
                     postexpnum.push(num2);
                }
            }
            else
            {
                ss<<postexp1.top();
                ss>>num1.num;
                num1.ge=0;
                postexpnum.push(num1);
            }
            postexp1.pop();
        }
        while(!postexpnum.empty())
        {
            cout<<postexpnum.top().num<<" "<<postexpnum.top().ge<<endl;
            postexpnum.pop();
        }


    }
    return 0;
}
