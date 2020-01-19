#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
long long int dp[2][10006];
long long int arr[10001];
int MAX = 10006;
long long int MOD = 1000000007;
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%lld", &arr[i]);
	dp[0][0] = arr[1]<1 ? 1 : 0;

	for (int i = 2; i <= N; i++)
	{
		fill_n(&dp[1][0], MAX, 0);

		if (arr[i] == -1)
		{
			dp[1][0] = (dp[0][0] + dp[0][1]) % MOD;
			for (int k = 1; k <= MAX / 2; k++)
				dp[1][k] = (dp[0][k - 1] + dp[0][k] + dp[0][k + 1]) % MOD;
		}
		else if (arr[i] == 0)
			dp[1][arr[i]] = (dp[0][arr[i]] + dp[0][arr[i] + 1]) % MOD;
		else
			dp[1][arr[i]] = (dp[0][arr[i] - 1] + dp[0][arr[i]] + dp[0][arr[i] + 1]) % MOD;

		swap(dp[0], dp[1]);
	}
	printf("%lld\n", dp[0][0]);
	return 0;
}