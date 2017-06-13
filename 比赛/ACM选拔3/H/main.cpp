#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <math.h>
#include <cstring>

using namespace std;
struct Point
{
    double x,y;
};
int main()
{
    int n;
    Point p[205];int c=0;
    while(~scanf("%d",&n),n)
    {
        for(int i=0; i<n;i++)
            scanf("%lf %lf",&p[i].x,&p[i].y);
        Point End=p[1];
        double Max=99999;
        for(int i=0;i<n;i++)
        {
            if(i==1)
                continue;
            double d = sqrt((End.x-p[i].x)*(End.x-p[i].x)+(End.y-p[i].y)*(End.y-p[i].y));
            if(d<Max)
                Max=d;
        }
        printf("Scenario #%d\n",++c);
        printf("Frog Distance = %.3lf\n",Max);
        if(n) printf("\n");
    }
    return 0;
}
