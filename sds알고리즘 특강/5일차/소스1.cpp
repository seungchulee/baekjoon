#include <stdio.h>
#include <cstring>
int dp[1001][21];
int main(void)
{
	int N, end;
	scanf("%d", &N);
	int arr[101];
	for (int i = 0; i < N-1; i++)
		scanf("%d", &arr[i]);
	
	scanf("%d", &end);
	memset(dp, 0, sizeof(dp));
	dp[0][arr[0]] = 1;

	for (int i = 0; i < N-1; i++)
	{
		
	}
	//printf("%d", dp[N - 1][end]);
}