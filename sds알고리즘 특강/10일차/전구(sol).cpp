#include <stdio.h>
#include <algorithm>
using namespace std;
int N, K;
int arr[201];
int dp[201][201];
int main(void)
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		for (int j = i; j--; )
		{
			dp[j][i] = 10000000;
			for (int k = j; k < i; k++)
			{
				dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i] + (arr[j] != arr[k + 1]));
			}
		}
	}
	printf("%d", dp[0][N - 1]);
	
}