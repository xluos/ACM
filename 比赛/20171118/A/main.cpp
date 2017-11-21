#include <bits/stdc++.h>

using namespace std;
map<int, string> M[4];
void init()
{
    M[0][1] = M[1][1] = "one";
    M[0][2] = M[1][2] = "two";
    M[0][3] = M[1][3] = "three";
    M[0][4] = M[1][4] = "four";
    M[0][5] = M[1][5] = "five";
    M[0][6] = M[1][6] = "six";
    M[0][7] = M[1][7] = "seven";
    M[0][8] = M[1][8] = "eight";
    M[0][9] = M[1][9] = "nine";
    M[0][0] = M[1][0] = "zero";

    M[2][1] = "ten";
    M[2][2] = "twenty";
    M[2][3] = "thirty";
    M[2][4] = "forty";
    M[2][5] = "fifty";
    M[2][6] = "sixty";
    M[2][7] = "seventy";
    M[2][8] = "eighty";
    M[2][9] = "ninety";

    M[3][0] = "ten";
    M[3][1] = "eleven";
    M[3][2] = "twelve";
    M[3][3] = "thirteen";
    M[3][4] = "fourteen";
    M[3][5] = "fifteen";
    M[3][6] = "sixteen";
    M[3][7] = "seventeen";
    M[3][8] = "eighteen";
    M[3][9] = "nineteen";

}
int main()
{
    int n;
    init();
    while(~scanf("%d",&n))
    {
        if(n==0) printf("zero\n");
        else
        {
            int flag = 0;
            char s[10];
            sprintf(s,"%04d",n);
            if(s[0]!='0')
            {
                cout<<M[0][s[0]-'0']<<" thousand";
                flag = 1;
            }
            if(s[1]!='0')
            {
                if(flag)
                {
                    cout<<" and ";
                    flag = 0;
                }
                cout<<M[1][s[1]-'0']<<" hundred";
                flag = 1;
            }

            if(s[2]!='0')
            {
                if(flag)
                {
                    cout<<" and ";
                    flag = 0;
                }
                if(s[2]!='1')
                {
                    cout<<M[2][s[2]-'0'];
                    flag = 2;
                }
                else
                {
                    cout<<M[3][s[3]-'0'];
                    flag = 3;
                }
            }
            if(flag<3&&s[3]!='0')
            {
                if(flag == 1)cout<<" and ";
                else if(flag == 2)cout<<'-';
                cout<<M[0][s[3]-'0'];
            }
            cout<<endl;
        }
    }
    return 0;
}
