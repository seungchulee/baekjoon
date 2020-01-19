#include <stdio.h>
int arr[51][201];
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	for (int i = 0; i < N; i++)
	{
		int ww = arr[i][0];
		int hh = arr[i][1];
		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (j == i)
				continue;
			if (ww < arr[j][0] && hh < arr[j][1])
				cnt++;
		}
		printf("%d ", cnt + 1);
	}
}