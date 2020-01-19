#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
long int arr[501][501];
long int dp[501][501];
int main(void)
{
	int n;
	scanf("%ld", &n);
	memset(arr, 0, sizeof(arr));
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%ld", &arr[i][j]);
		}
	}
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}
	long int result = -1;
	for (int i = 1; i <= n; i++)
	{
		result = max(result, dp[n][i]);
	}
	printf("%ld", result);
	
}