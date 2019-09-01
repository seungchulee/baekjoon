#include <stdio.h>
int N;

long long int X;
long long int B[51];
long long int P[51];
long long int beef(int n, long long int x)
{
	if(n==0)
	{
		if(x==0)
			return 0;
		else 
			return 1;

	}
	else if(x==1)
	{
		return 0;
	}
	else if(x<=1+B[n-1])
	{
		printf("!!%lld!!\n",beef(n-1,x-1));
		return beef(n-1,x-1);
	}
	else if(x==2+B[n-1])
	{
		return P[n-1]+1;
	}
	else if(x<=2+2*B[n-1])
	{
		return P[n-1]+1+beef(n-1,x-2-B[n-1]);
	}
	else
		return P[n-1]+1+P[n-1];
}
int main(void)
{
	scanf("%d %lld",&N,&X);

	B[0]=1;
	P[0]=1;
	for(int i=1;i<=N;i++)
	{
		B[i]=2*B[i-1]+3;
		P[i]=2*P[i-1]+1;
	}
	printf("%lld",beef(N,X));
}
