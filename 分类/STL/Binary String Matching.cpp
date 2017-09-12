#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char a[1088],b[20];
int next[20],n,m;
void Next()//就是上面的分匹配表的实现
{
    int i,j;
    i=0;
    j=-1;
    next[i]=j;   //匹配表初值
    while(i<m)
    {
        if(j==-1||b[i]==b[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
    return ;
}
int KMP()//kmp匹配算法
{
    int i,j,sum=0;
    i=j=0;
    Next();//先计算部分匹配表
    while(i<n)
    {
        if(j==-1||a[i]==b[j])
        {
            i++;
            j++;
            if(j==m)
                sum++;//找到目标字符串，返回到主程序。
        }
        else
            j=next[j];//a[i]与b[j]不匹配，查表需要跳过的字符个数。
    }
    return sum;//没有找到返回-1
}

int main()
{
	int w;cin>>w;
	while(w--)
	{
		scanf("%s %s",b,a);
		n=strlen(a);
		m=strlen(b);
		cout<<KMP()<<endl;
	}
    return 0;
}


