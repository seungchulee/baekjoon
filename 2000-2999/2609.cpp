#include <stdio.h>
#include <algorithm>
using namespace std;
int gcd(int a, int b)
{
	if(a>b)
		swap(a,b);
	while(a!=0)
	{
		int re = b%a;
		b=a;
		a=re;
	}
	return b;
}
int main(void)
{
	
	int a=0, b=0,max=0,min=0;
	int t=0,s=0;
	scanf("%d %d", &a, &b);
	printf("%d\n",gcd(a,b));
	printf("%d\n",a*b/gcd(a,b));
	return 0;

}
