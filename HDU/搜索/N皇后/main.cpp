#include <bits/stdc++.h>

using namespace std;

int n, ans;
int limit;

void dfs( int row, int rd, int ld ) {
    if ( row == limit ) {  //˵��n�ж�վ����
        ans++;
        return;
    }
    int pos = limit & (~(row|rd|ld)),p; //pos�Ķ�����λ0�ģ��������limit����ʡ��limit��֤��pos����n��λΪ0
    while ( pos ) {
        p = pos & (-pos); //������㣬��ԭ��Ͳ���ȡ������㣬���Եó����ұߵ�1��
        //pos &��~pos +1������������Ч����ͬ
        pos -= p;
        dfs( row+p, (rd+p)<<1, (ld+p)>>1 );
    }
}
int main()
{
    while ( scanf("%d", &n),n ) {
        ans = 0;
        limit = ( 1<<n ) - 1; //limit�Ķ�������n��1��
        dfs( 0, 0, 0 );
        printf("%d\n", ans);
    }
}


/**
//�����鷽��
int n,sum;
int main()
{
    int num[]={0,1,0,0,2,10,4,40,92,352,724};
    while(~scanf("%d",&n),n)
    {

        cout<<num[n]<<endl;
    }
    return 0;
}

*/
