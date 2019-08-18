#include <stdio.h>

int main(void)
{
	int N=64;
	int n;
	int cnt=0;

	scanf("%d",&n);
	for(int i=0;;i++)
	{
		if(n>N)
		{
			n-=N;
			cnt++;
		}
		if(n<N)
			N/=2;
		if(n==N)
		{
			cnt++;
			break;
		}
	}
	printf("%d",cnt);

}
