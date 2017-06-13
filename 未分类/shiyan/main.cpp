#include <iostream>
#include<windows.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

template <class T>
inline void scan_d(T &ret)
{
    char c;
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
int main()
{
//    int size = 1858 << 20; // 1024MB
//char *p = (char*)malloc(size) + size;
//__asm__("movl %0, %%esp\n" :: "r"(p));
//    xun(1);
    LARGE_INTEGER lFrequency;
    QueryPerformanceFrequency(&lFrequency);
//��ȡCPU��ʱ��Ƶ��
    LARGE_INTEGER lBeginCount;
    QueryPerformanceCounter(&lBeginCount);
    freopen("in.txt","r",stdin);
    int a;
    for(int i=0;i<10000000;i++)
    {
        scanf("%d",&a);
    }
    fclose(stdin);
    LARGE_INTEGER lEndCount;
    QueryPerformanceCounter(&lEndCount);
    double time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;
//�õ�����ʱ�䣬��λ��
    printf("scanf����ʱ��%lf����\n",time*1000);
    QueryPerformanceCounter(&lBeginCount);
    freopen("in.txt","r",stdin);
    for(int i=0;i<10000000;i++)
    {
        cin>>a;
    }
    fclose(stdin);
    QueryPerformanceCounter(&lEndCount);
    time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;
//�õ�����ʱ�䣬��λ��
    printf("cin����ʱ��%lf����\n",time*1000);
    ios::sync_with_stdio(false);
    QueryPerformanceCounter(&lBeginCount);
    freopen("in.txt","r",stdin);
    for(int i=0;i<10000000;i++)
    {
        cin>>a;
    }
    fclose(stdin);
    QueryPerformanceCounter(&lEndCount);
    time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;
//�õ�����ʱ�䣬��λ��
    printf("cin�ر�ͬ������ʱ��%lf����\n",time*1000);
    QueryPerformanceCounter(&lBeginCount);
    freopen("in.txt","r",stdin);
    for(int i=0;i<10000000;i++)
    {
        scan_d(a);
    }
    fclose(stdin);
    QueryPerformanceCounter(&lEndCount);
    time = (double)(lEndCount.QuadPart - lBeginCount.QuadPart) / (double)lFrequency.QuadPart;
//�õ�����ʱ�䣬��λ��
    printf("��������ʱ��%lf����\n",time*1000);
    return 0;
}
