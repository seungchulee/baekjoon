#include <stdio.h>
#include <cmath>
using namespace std;
int main(void)
{
	long long int n;
	long long int res=0;
	scanf("%lld",&n);
	if(n<10)
		printf("%lld",n);
	else
	{	
		int ll = n;
		int len=0;
		while(ll>=1)
		{
			ll/=10;
			len++;
		}

		long long int gu = 9;
		for(int i=1;i<len;i++)
		{
			res+=i*gu;
			gu*=10;
		}

		res+=(n-(int)pow(10,len-1)+1)*len;
		printf("%lld",res);
	}
		
}
