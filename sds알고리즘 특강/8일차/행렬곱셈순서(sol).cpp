#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
int arr[501][2];
int dp[501][501];
int main(void)
{
	int N;
	scanf("%d", &N);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= N; i++)
	{
		int r, c;
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	for (int i = 1; i < N; i++)
	{
		dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
	}
	for (int m = 2; m <= N; m++)
	{
		for (int i = 1; i <= N - m; i++)
		{
			int j = i + m;
			for (int k = i; k < j; k++)
			{
				int res = dp[i][k] + dp[k + 1][j] + arr[i][0] * arr[k][1] * arr[j][1];
				if (res < dp[i][j] || dp[i][j]==0)
					dp[i][j] = res;
			}
		}

	}
	printf("%d", dp[1][N]);
}