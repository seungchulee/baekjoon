#include <stdio.h>
long long int dp[33][33];
int main(void)
{
	int T;
	scanf("%d", &T);
	dp[0][0] = 0;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 30; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
		}
	}
	for (int t = 0; t < T; t++)
	{
		int N, K;
		scanf("%d %d",&N, &K);
		printf("%lld\n", dp[K][N]);
	}
}