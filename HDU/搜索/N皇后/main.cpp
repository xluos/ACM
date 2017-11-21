#include <bits/stdc++.h>

using namespace std;

int n, ans;
int limit;

void dfs( int row, int rd, int ld ) {
    if ( row == limit ) {  //说明n列都站满了
        ans++;
        return;
    }
    int pos = limit & (~(row|rd|ld)),p; //pos的二进制位0的，并且这个limit不能省，limit保证了pos高于n的位为0
    while ( pos ) {
        p = pos & (-pos); //这个运算，即原码和补码取与的运算，可以得出最右边的1；
        //pos &（~pos +1）这两个操作效果相同
        pos -= p;
        dfs( row+p, (rd+p)<<1, (ld+p)>>1 );
    }
}
int main()
{
    while ( scanf("%d", &n),n ) {
        ans = 0;
        limit = ( 1<<n ) - 1; //limit的二进制是n个1；
        dfs( 0, 0, 0 );
        printf("%d\n", ans);
    }
}


/**
//抖机灵方法
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
