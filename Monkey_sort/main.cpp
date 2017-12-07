#include <bits/stdc++.h>
#include<time.h>
using namespace std;
const int MAX = 10;
struct node{
    int ms;
    int data;
};
bool cmp(node a,node b)
{
    return a.ms<b.ms;
}
int main()
{
    srand(time(0));
    int b[MAX];
    node a[MAX];
//    printf("输入%d个数\n",MAX);
//    for(int i=0;i<MAX;i++)
//    {
//        cin>>a[i].data;
//        b[i] = a[i].data;
//    }
    for(int i=0;i<MAX;i++)
    {
        a[i].data = rand()%100;
        b[i] = a[i].data;
    }
    sort(b,b+MAX);
    for(int i=0;i<MAX;i++)
    {
        cout<<b[i]<<' ' ;
    }
    cout<<"开始猴子排序"<<endl;
    int k = 1;
    while(1)
    {
        if(!(k%100000))
            printf("第%d次猴子排序\n",k);
        srand(k*rand());
        for(int i=0;i<MAX;i++)
        {
            a[i].ms = rand();
        }
        sort(a,a+MAX,cmp);
        int i;
        for(i=0;i<MAX;i++)
        {
            if(a[i].data != b[i])
            {
                if(!(k%100000))
                printf("第%d次猴子排序----失败",k);
                break;
            }
        }
        if(i == MAX)
        {
            printf("第%d次猴子排序----成功",k);
            for(int i=0;i<MAX;i++)
            {
                cout<<a[i].data<<' ';
            }
            cout<<endl;
            break;
        }
        if((!(k%100000)))
        {
            for(int i=0;i<MAX;i++)
        {
            cout<<a[i].data<<' ';
        }
        cout<<endl;
        }

        k++;
    }
    return 0;
}
