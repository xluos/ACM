#include <stdio.h>
#include<math.h>
int main()
{
int i;
double x1, y1, x2, y2;
scanf("%d", &i);
while(i--)
{
double s=0, c=0;
scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
c=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
s=sqrt(c);
printf("%0.2lf\n",s);

}
return 0;
}
