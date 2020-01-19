#include <stdio.h>
int N;
long int M;
int arr[10001];
int main(void)
{
	scanf("%d %ld", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	/*int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		
		for (int j = i; j < N; j++)
		{
			num += arr[j];
			if (num == M)
				ans++;
		}

	}*/
	int i = 0;
	int j = 0;
	int num = 0;
	int ans = 0;
	while (1)
	{
		
		if (num > M)
		{
			num -= arr[i];
			i++;
		}
		else if (j == N)
			break;
		else
		{
			num += arr[j];
			j++;
		}

		if (num == M)
			ans++;
	}
	printf("%d", ans);
}
