#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <limits.h>
using namespace std;
long long int dp[201][201];
int main(void)
{
	int N, M;
	long long int K;
	scanf("%d %d %lld", &N, &M, &K);

	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 200; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				dp[i][j] = 1;
			else
			{
				if (dp[i-1][j-1]+dp[i-1][j]>1000000000)
					dp[i][j] = INT_MAX;
				else
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
	}
	//printf("%lld", dp[N + M][M]);
	if (dp[N + M][M] < K)
	{
		//if (dp[N + M][M] == INT_MAX)
			//printf("int max\n");
		printf("-1");
		return 0;
	}
	int n = N;
	int m = M;
	long long int k = K;
	for (int i = 0; i < N + M; i++)
	{
		//printf("%dc %d %d\n", n, m, K);
		if (dp[n + m - 1][m] < k)
		{
			// z 로 시작
			if (m == 0)
			{
				printf("a");
				continue;
			}
			printf("z");
			k -= dp[n + m-1][m];
			m--;
 		}
		else
		{
			// a 로 시작
			if (n == 0)
			{
				printf("z");
				continue;
			}
			printf("a");
			n--;
		}
	}

}