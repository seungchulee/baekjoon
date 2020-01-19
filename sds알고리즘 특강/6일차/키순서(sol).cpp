#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[501][501];
int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= 500; i++)
	{
		for (int j = 1; j <= 500; j++)
		{
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = 10000000;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}
	int result = 0;
	for (int k = 1; k <= N; k++)
	{
		for (int a = 1; a <= N; a++)
		{
			for (int b = 1; b <= N; b++)
			{
				arr[a][b] = min(arr[a][b], arr[a][k] + arr[k][b]);
			}
		}
	}
	for (int k = 1; k <= N; k++)
	{
		int left = 0;
		int right = 0;
		for (int a = 1; a <= N; a++)
		{
			if (arr[a][k] != 0 && arr[a][k] != 10000000)
				left++;
		}
		for (int a = 1; a <= N; a++)
		{
			if (arr[k][a] != 0 && arr[k][a] != 10000000)
				right++;
		}
		
		if (left + right == N - 1)
			result++;
	}

	printf("%d", result);

}