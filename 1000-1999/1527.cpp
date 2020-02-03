#include <stdio.h>
int result=0;
long long int a,b;
void get(long long int num)
{
	if(num>b)
		return;
	if(num>=a && num<=b)
		result++;
	get(num*10+4);
	get(num*10+7);
}
int main(void)
{
	scanf("%lld %lld",&a,&b);
	get(4);
	get(7);
	printf("%d",result);
}
