#include <bits/stdc++.h>

using namespace std;
struct node
{

    int sheng,fu,ping;
    map<char,int>mp;
    node()
    {
        sheng=fu=ping=0;
    }
};
void input_jcb(node *J)
{
    if(J->mp['B']>=J->mp['C']&&J->mp['B']>=J->mp['J'])
    {
        printf("B");
    }
    else if(J->mp['C']>=J->mp['B']&&J->mp['C']>=J->mp['J'])
    {
        printf("C");
    }
    else if(J->mp['J']>=J->mp['B']&&J->mp['J']>=J->mp['C'])
    {
        printf("J");
    }
}
int main()
{
    int n;
    cin>>n;
    char ch,ch2;
    node *J = new node;
    node *Y = new node;
    while(n--)
    {


        cin>>ch>>ch2;
        if(ch=='B'&&ch2=='B'||ch=='C'&&ch2=='C'||ch=='J'&&ch2=='J')
        {
            J->ping++;
            Y->ping++;
        }
        if(ch=='B'&&ch2=='C')
        {
            J->sheng++;
            Y->fu++;
            J->mp['B']++;
        }
        if(ch=='B'&&ch2=='J')
        {
            Y->sheng++;
            J->fu++;
            Y->mp['J']++;
        }
        if(ch=='C'&&ch2=='J')
        {
            J->sheng++;
            Y->fu++;
            J->mp['C']++;
        }
        if(ch=='C'&&ch2=='B')
        {
            Y->sheng++;
            J->fu++;
            Y->mp['B']++;
        }
        if(ch=='J'&&ch2=='C')
        {
            Y->sheng++;
            J->fu++;
            Y->mp['C']++;
        }
        if(ch=='J'&&ch2=='B')
        {
            J->sheng++;
            Y->fu++;
            J->mp['J']++;
        }
    }
    printf("%d %d %d\n",J->sheng,J->ping,J->fu);
    printf("%d %d %d\n",Y->sheng,Y->ping,Y->fu);
    input_jcb(J);
    cout<<' ';
    input_jcb(Y);
    cout<<endl;
    return 0;
}
