/*这题前提应该是所有人都不知道黑帽子一共有几个
1）假如黑帽子是1个，那如果A戴黑帽子，第一次开灯他就能看到所有人是白帽子，于是打自己
2）假如黑帽子是2个，A和B戴黑帽子，第一次开灯A看到B是黑帽子其他人全是白帽子，关灯后A发现B没打自己，于是知道B看到了另外一个黑帽子，那肯定是A自己，于是第二次开灯关灯后A就打自己
3）假如黑帽子是3个，A,B,C都戴黑帽子，第一次开灯A看到B,C是黑帽子其他人全是白帽子，关灯后A发现B和C没打自己；但不一定是因为A自己戴了黑帽子，有可能是B和C互相看到各自的黑帽子。第二次开灯后关灯后A发现B和C还是没有打自己，于是肯定除了他们之外还有一个黑帽子，因为如果A自己是白帽子那就会出现 2）的情况。于是第三次开灯关灯后A就打自己了。
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n,w;cin>>w;
	while(w--)
	{
		scanf("%d",&n);
		printf("%d\n",n);
	}
    return 0;
}


