//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//int s[25],s2[25];
//void LCS(int l,int l2)
//{
//    int dp[2][25];
//    memset(dp,0,sizeof(dp));
//    for(int i=0;i<l;i++)
//    {
//        for(int j=0;j<l2;j++)
//        {
//            if(i==0||j==0)
//                dp[i%2][j] = 0;
//            else if(s[i]==s2[j])
//                dp[i%2][j] = dp[(i+1)%2][j-1] + 1;
//            else
//                dp[i%2][j] = max(dp[(i+1)%2][j] ,dp[i%2][j-1]);
//            cout<< dp[i%2][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<dp[(l-1)%2][l2-1]<<endl;
//}
//int main()
//{
//    int w;cin>>w;
//    while(w--)
//    {
//        int n;cin>>n;
//        for(int i=1;i<=n;i++)
//        {
//
//            scanf("%d",&s[i]);
//            s2[i]=s[i];
//        }
//        sort(s2,s2+n+1);
//        LCS(n+1,n+1);
//    }
//
//
//    return 0;
//}
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define N 100005
using namespace std;

//int main()                //动态规划解法  O（N~2）
//{
//	int w,x[N],l[N],max=0;
//	int n;cin>>n;
//	while(n--)
//	{
//        max=1;
//        cin>>w;
//        for(int i=0;i<w;i++)
//        {
//            cin>>x[i];
//            l[i]=1;
//        }
//        for(int i=1;i<w;i++)
//            for(int j=0;j<i;j++)
//            {
//                if(x[j]<x[i]&&l[i]<=l[j])
//                {
//                    l[i]=l[j]+1;
//                    if(max<l[i])max=l[i];
//                }
//            }
//	cout<<max<<endl;
//    }
//    return 0;
//}
int _2fen(int n[],int l,int a)
{
	int mid,head=0,tail=l-1;
	while(head<=tail)
	{
		mid=(head+tail)/2;
		if(n[mid]<a)
			head=mid+1;
		else if(n[mid]>a)
			tail=mid-1;
		else
			return mid;
	}
	return head;
}
int lis(int a[],int n)
{
	int vis[N],k=1;
	vis[0]=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]>vis[k-1])
		{
			vis[k++]=a[i];
		}
		else
		{
			int mid=_2fen(vis,k,a[i]);
			vis[mid]=a[i];
		}
	}
	return k;
}
int main()
{
	int w,x[N];
    while(cin>>w){

	for(int i=0;i<w;i++)
	{
		scanf("%d",&x[i]);
	}
	cout<<lis(x,w)<<endl;}
	return 0;
}

/**

#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX=100100;
int num[MAX],top=0;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		scanf("%d",&num[0]);
		top=1;
		for(int i=1;i!=n;i++)
		{
			scanf("%d",&num[i]);
			int * p=lower_bound(num,num+top,num[i]);
			if(p-num==top) ++top;
			*p=num[i];
		}
		printf("%d\n",top);
	}

}

*/
