#include<stdio.h>
#include<math.h>
#include <stdlib.h>
int get_i(int w,int n)
{
	return (n-1)/w;
} 
int get_j(int w,int n)
{
	return get_i(w, n) % 2 ? ( w - ( ( n - 1 ) % w ) - 1 ) : ( ( n - 1 ) % w );
}
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int w,n,m;
	int n_i,n_j,m_i,m_j;
	scanf("%d %d %d",&w,&n,&m);
	n_i = get_i(w,n);
	n_j = get_j(w,n);
	m_i = get_i(w,m);
	m_j = get_j(w,m);
	printf("%d\n",max(n_i,m_i) - min(n_i,m_i) + max(n_j, m_j) - min(n_j, m_j));
	return 0;	
} 
