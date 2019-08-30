#include <stdio.h>
long long int dp[101];
int main(void)
{
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	dp[4]=2;
	dp[5]=2;
	dp[6]=3;
	int N;
	scanf("%d",&N);
	for(int i=7;i<101;i++)
	{
		dp[i]=dp[i-1]+dp[i-5];
	}
	for(int i=0;i<N;i++)
	{
		int a;
		scanf("%d",&a);
		printf("%lld\n",dp[a]);
	}
}

