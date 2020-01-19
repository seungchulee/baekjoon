#include <stdio.h>
int arr[9][9];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int gaesu = 0;
int cnt = 0;
int check(int x, int y)
{
	for (int i = 1; i <= 9; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			int ddx = x + i*dx[k];
			int ddy = y + i*dy[k];
			if (ddx < 0 || ddy < 0 || ddx >= 9 || ddy >= 9)
				continue;
			if (arr[ddx][ddy] == arr[x][y])
				return -1;
		}
	}
	return 0;
}
void print()
{
	printf("------\n");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("-------\n");
}
void DFS(int num)
{
	//printf("!");
	if (num == 0 && cnt==0)
	{
		cnt++;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		//printf("\n");
		return;
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == 0)
			{
				for (int k = 1; k <= 9; k++)
				{
					arr[i][j] = k;
					int ch = check(i, j);
					if (ch == -1)
					{
						continue;
					}
					num--;
					DFS(num);
				}
			}

		}
	}
}
int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)
				gaesu++;
		}
	}
	DFS(gaesu);
}