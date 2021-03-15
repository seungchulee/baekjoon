#include <stdio.h>
#include <cstring>
using namespace std;
int arr[1001][1001];
int main(void)
{
	int C;
	scanf("%d", &C);
	memset(arr, -1, sizeof(arr));

	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
		{
			if (arr[i][j] == -1)
			{
				int start = 2;
				while (1)
				{
					if (i*start > 1000 || j*start > 1000)
						break;
					arr[i*start][j*start] = 1;
					start++;
				}
			}
		}
	}
	for (int t = 0; t < C; t++)
	{
		int N;
		scanf("%d", &N);

		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (arr[i][j] == -1)
					cnt++;
			}
		}
		printf("%d\n", cnt+2);
	}
}