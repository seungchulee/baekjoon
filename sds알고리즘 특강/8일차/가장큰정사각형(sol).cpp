#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int main(void)
{
	int n, m;
	memset(dp, 0, sizeof(dp));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &dp[i][j]);
		}
	}
	int maxs = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (dp[i][j] == 0)
				continue;
			else
			{
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
				maxs = max(maxs, dp[i][j]);
			}
		}
	}
	if (maxs == -1)
		printf("0");
	else
		printf("%d", maxs*maxs);
}