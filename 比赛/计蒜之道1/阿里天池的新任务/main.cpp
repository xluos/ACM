#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n,a,b,l,r,wi,m,ii;
char s[3000009],t[1000009];
int neaxttt[1000009];
int w(int i)
{
    if(i==0)
        return b;
    return (wi+a)%n;
}
char S(int i)
{
    wi=w(i);
    if(wi<=r&&wi>=l)
    {
        if(wi%2)
            return 'T';
        return 'A';
    }
    else
    {
        if(wi%2)
            return 'C';
        return 'G';
    }
}
void Neaxt(char b[])
//����ƥ����ʵ��
{
    int i,j;
    i=0;
    j=-1;
    neaxttt[i]=j;
    while(i<m)
    {
        if(j==-1||b[i]==b[j])
        {
            i++;
            j++;
            neaxttt[i]=j;
        }
        else
            j=neaxttt[j];
    }
    return ;
}
int KMP(char a[],char b[])//kmpƥ���㷨
{
    int i,j,sum=0,ans=0;
    i=j=0;
    Neaxt(b);//�ȼ��㲿��ƥ���
    while(i<n)
    {
        if(ans>1000000)
        {
            int j=ii%3000001;
            for(;j<1000000;ii++,j=ii%3000001)
                s[j]=S(j);
        }
        if(j==-1||a[i%3000001]==b[j])
        {

            i++;
            ans++;
            j++;
            if(j==m)
              sum++;//�ҵ�Ŀ���ַ��������ص�������
        }
        else
            j=neaxttt[j];//a[i]��b[j]��ƥ�䣬�����Ҫ�������ַ�������
    }
    return sum;//û���ҵ�����-1
}
int main()
{
    scanf("%d %d %d %d %d",&n,&a,&b,&l,&r);
    for(ii=0;ii<3000000;ii++)
        s[ii]=S(ii);
    s[ii]=0;
    scanf("%s",t);
    m=strlen(t);
    cout<<KMP(s,t)<<endl;
    return 0;
}
