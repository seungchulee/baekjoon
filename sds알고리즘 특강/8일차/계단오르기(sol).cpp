#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[301];
int dp[301];
int main(void)
{
	int N;
	scanf("%d", &N);
	arr[0] = 0;
	dp[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= N; i++)
	{
		dp[i] = arr[i] + max(arr[i-1]+dp[i-3],dp[i-2]);
	}
	printf("%d", dp[N]);
}