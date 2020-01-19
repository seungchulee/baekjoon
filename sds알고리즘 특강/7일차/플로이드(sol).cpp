#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int arr[101][101];
int main(void)
{
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = 10000000;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (arr[a][b] == 10000000)
			arr[a][b] = c;
		else
			arr[a][b] = min(arr[a][b], c);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int a = 1; a <= n; a++)
		{
			for (int b = 1; b <= n; b++)
			{
				arr[a][b] = min(arr[a][b], arr[a][k] + arr[k][b]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 10000000)
				printf("0 ");
			else
				printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	
}
