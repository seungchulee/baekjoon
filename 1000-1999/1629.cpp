#include <stdio.h>
long long int cal(long long int a, long long int b, long long int c)
{
	if(b==0)
		return 1;
	else if(b==1)
		return a;
	if(b%2>0)
		return cal(a,b-1,c)*a;
	long long int tmp = cal(a,b/2,c);
	tmp%=c;
	return (tmp*tmp)%c;
}
int main(void)
{
	long long int a,b,c;
	scanf("%lld %lld %lld",&a,&b,&c);
	long long int res;
	res=cal(a,b,c);
	printf("%lld",res%c);
}
