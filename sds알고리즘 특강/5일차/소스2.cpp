#include <stdio.h>
int arr[1001][1001];
int main(void)
{
	int H, W,N;
	scanf("%d %d %d", &H, &W, &N);
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}


}