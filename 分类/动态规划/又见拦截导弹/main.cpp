#include <bits/stdc++.h>
#define N 3005
using namespace std;

int lis(int a[],int n)//a[]Ϊ��������У�nΪ���г���
{
    int vis[N],k=1;
    vis[0]=a[0];
    for(int i=1; i<n; i++)
    {
        if(a[i]>vis[k-1])  //��������
        {
            vis[k++]=a[i];
        }
        else
        {
            int mid=lower_bound(vis,vis+k,a[i])-vis;
            vis[mid]=a[i];
        }
    }
    return k; //����lis����
}
int main()
{
    int w,x[N];
    //LIS  �����������   O��Nlongn��
    while(scanf("%d",&w),w!=-1)
    {
        for(int i=0; i<w; i++)
        {
            scanf("%d",&x[i]);
        }
        cout<<lis(x,w)<<endl;
    }
    return 0;
}
