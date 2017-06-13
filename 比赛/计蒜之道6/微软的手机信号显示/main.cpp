#include <bits/stdc++.h>

using namespace std;
void input_4g()
{
    printf("|-  4G|\n");
    return ;
}
void input_3g()
{
    printf("|-  3G|\n");
    return ;
}
void input_e(int x)
{
    if(x)
        printf("|-   E|\n");
    else
        printf("|    E|\n");
    return ;
}
void input_xh(int n)
{
    printf("+-----+\n");
    switch(n)
    {
    case 10:
    case 9:
        input_4g();
        break;
    case 8:
    case 7:
    case 6:
        input_3g();
        break;
    default:
        input_e(n);
        break;
    }
    if(n>=4)
        printf("|--   |\n");
    else
        printf("|     |\n");
    if(n>=6)
        printf("|---  |\n");
    else
        printf("|     |\n");
    if(n>=8)
        printf("|---- |\n");
    else
        printf("|     |\n");
    if(n>=10)
        printf("|-----|\n");
    else
        printf("|     |\n");
    printf("+-----+\n");

}
int main()
{
    int n;
    scanf("%d",&n);
    input_xh(n/10);
    return 0;
}
