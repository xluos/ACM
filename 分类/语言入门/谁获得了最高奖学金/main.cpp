#include <iostream>
#include <stdio.h>
using namespace std;
struct stm{
    char neam[25],ganbu,xibu;
    int qimo,banji,lunwen,sum;
};
int yuanshi(stm x)
{
    if(x.qimo>80&&x.lunwen>=1)
        return 8000;
    return 0;
}
int wusi(stm x)
{
    if(x.qimo>85&&x.banji>80)
        return 4000;
    return 0;
}
int youxiu(stm x)
{
    if(x.qimo>90)
        return 2000;
    return 0;
}
int xibu(stm x)
{
    if(x.qimo>85&&x.xibu=='Y')
        return 1000;
    return 0;
}
int gongxian(stm x)
{
    if(x.banji>80&&x.ganbu=='Y')
        return 850;
    return 0;
}
int jiangjin(stm x)
{
    return yuanshi(x)+wusi(x)+youxiu(x)+xibu(x)+gongxian(x);
}
int main()
{
    int w;cin>>w;
    while(w--)
    {
        stm st[111];
        int k;cin>>k;
        int sum=0,mark,max=-1;
        for(int i=0;i<k;i++)
        {

            scanf("%s %d %d %c %c %d",st[i].neam,&st[i].qimo,&st[i].banji,&st[i].ganbu,&st[i].xibu,&st[i].lunwen);
            st[i].sum=jiangjin(st[i]);
            sum+=st[i].sum;
            if(st[i].sum>max){max=st[i].sum;mark=i;}
        }
        printf("%s\n%d\n%d\n",st[mark].neam,st[mark].sum,sum);
    }
    return 0;
}
