#include <stdio.h>
#include <cstring>
int dp[1001][1001];
int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 0;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 1000; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j==i)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%10007;
		}
	}
	printf("%d", dp[N][K]);
}