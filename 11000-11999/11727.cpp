#include <stdio.h>
int dp[1010];
int main(void)
{
	dp[1]=1;
	dp[2]=3;
	for(int i=3;i<=1000;i++)
		dp[i]=(dp[i-1]+dp[i-2]*2)%10007;
	int n;
	scanf("%d",&n);
	printf("%d",dp[n]);
}
