#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;
int arr[101][101];
int main(void)
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)
				arr[i][j] = 10000000;

		}
	}

	for (int k = 0; k < N; k++)
	{
		for (int a = 0; a < N; a++)
		{
			for (int b = 0; b < N; b++)
			{
				arr[a][b] = min(arr[a][b], arr[a][k] + arr[k][b]);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 10000000)
				printf("0 ");
			else
				printf("1 ");
		}
		printf("\n");
	}
}