#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include <iostream>
using namespace std;
const int INF=-0x3fffffff;
stack<int>s;
int dp[101],pre[101],a[10001];
int main(void){
    //freopen("in.txt","r",stdin);
    for(int i=0;i<=100;++i){
        dp[i]=INF;
        pre[i]=-1;
    }
    dp[0]=0;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    sort(&a[1],&a[1]+n);
    for(int i=1;i<=n;++i){
        for(int j=m;j>=a[i];--j){
            if(dp[j]<=dp[j-a[i]]+1){
                //�ӵȺ�����Ϊ��Ӳ�Ҹ�����ͬ������£�������һö���������һö��С���Ӷ�ʹ���ֵ�����С
                dp[j]=dp[j-a[i]]+1;
                pre[j]=j-a[i];//��¼·��
                
            }
        }
    }
    for(int i=0;i<10;i++)
    cout<<i<<" "<<pre[i]<<endl;
    if(dp[m]>0){
        int k=m;
        while(pre[k]){
            s.push(k-pre[k]);
            k=pre[k];
        }
        printf("%d",k);
        while(!s.empty()){
            printf(" %d",s.top());
            s.pop();
        }
        printf("\n");
    }else printf("No Solution\n");
    return 0;
}

