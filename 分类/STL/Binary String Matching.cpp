#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char a[1088],b[20];
int next[20],n,m;
void Next()//��������ķ�ƥ����ʵ��
{
    int i,j;
    i=0;
    j=-1;
    next[i]=j;   //ƥ����ֵ
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
int KMP()//kmpƥ���㷨
{
    int i,j,sum=0;
    i=j=0;
    Next();//�ȼ��㲿��ƥ���
    while(i<n)
    {
        if(j==-1||a[i]==b[j])
        {
            i++;
            j++;
            if(j==m)
                sum++;//�ҵ�Ŀ���ַ��������ص�������
        }
        else
            j=next[j];//a[i]��b[j]��ƥ�䣬�����Ҫ�������ַ�������
    }
    return sum;//û���ҵ�����-1
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


