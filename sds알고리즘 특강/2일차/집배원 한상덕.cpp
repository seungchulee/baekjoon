#include <stdio.h>
int N;
char map[51][51];
int height[51][51];
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,-1,1,1,-1,1,-1 };
int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", map[i]);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &height[i][j]);
		}
	}
}