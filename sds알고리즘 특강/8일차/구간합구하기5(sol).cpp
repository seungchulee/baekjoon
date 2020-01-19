#include <stdio.h>
#include <cstring>
long int arr[1025][1025];
long int dp[1025][1025];
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	memset(arr, 0, sizeof(arr));
	memset(dp, 0, sizeof(dp));
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%ld", &arr[i][j]);
			dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1]-dp[i-1][j-1];
		}
	}
	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%ld\n", dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1]);
	}

}