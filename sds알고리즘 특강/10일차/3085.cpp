#include <stdio.h>
#include <algorithm>
using namespace std;
char arr[51][51];
int dx[4] = { 0,1 };
int dy[4] = { 1,0 };
int N;
int res = -1;
void get_max()
{
	int maxs = -1;
	int ans = 1;
	for (int i = 0; i < N; i++)
	{
		ans = 1; 
		for (int j = 0; j < N-1; j++)
		{
			if (arr[i][j] == arr[i][j + 1])
				ans++;
			else
				ans = 1;
			maxs = max(maxs, ans);
		}
	}
	for (int i = 0; i < N; i++)
	{
		ans = 1;
		for (int j = 0; j <N-1; j++)
		{
			if (arr[j][i] == arr[j+1][i])
				ans++;
			else
				ans = 1;
			maxs = max(maxs, ans);
		}
	}

	//printf("!!%d!!\n", maxs);
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%c ", arr[i][j]);
		printf("\n");
	}*/
	res = max(maxs, res);
}
int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", arr[i]);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				int ddx = i + dx[k];
				int ddy = j + dy[k];
				if (ddx < 0 || ddy < 0 || ddx >= N || ddy >= N)
					continue;
				if (arr[i][j] != arr[ddx][ddy])
				{
					swap(arr[i][j], arr[ddx][ddy]);
					// printf("%d %d %d %d\n", i, j, ddx, ddy);
					get_max();
					swap(arr[i][j], arr[ddx][ddy]);
				}
			}
		}
	}
	printf("%d", res);
}