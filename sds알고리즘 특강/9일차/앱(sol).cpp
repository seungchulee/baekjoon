#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int A[101];
int m[101];
int dp[101][10001];
int main(void)
{
	int N;
	int M;
	scanf("%d %d", &N,&M);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &m[i]);
		sum += m[i];
	}
	memset(dp, 0, sizeof(dp));
	dp[0][m[0]] = A[0];
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j >= m[i])
				dp[i][j] = max(dp[i-1][j - m[i]] + A[i], dp[i][j]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	int mins = 100000;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (dp[i][j] >= M)
				mins = min(mins, j);
		}
	}
	printf("%d", mins);
}