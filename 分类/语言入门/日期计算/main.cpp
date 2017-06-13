#include <iostream>

using namespace std;
int rn(int n)
{
    if ((n%4==0&&n%100!=0)||n%400==0)
        return 1;
    return 0;
}
int main()
{
    int yue[]={0,31,59,90,120,151,181,212,243,273,304,334};
    int n,y,r,k;
    cin>>k;
    while(k--)
    {
        cin>>n>>y>>r;
        if(rn(n)&&y>2)
            cout<<yue[y-1]+r+1<<endl;
        else
            cout<<yue[y-1]+r<<endl;
    }
    return 0;
}
